// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include <math.h>
#include "renderer.hpp"

//#include "scene.hpp"

Renderer::Renderer()
    :
    scene_{},
    colorbuffer_(scene_.xres_*scene_.yres_, Color{}),
    ppm_(scene_.xres_, scene_.yres_, "default.ppm")
    {}

Renderer::Renderer(Scene scene)
    : /*width_{scene->xres_}
    , height_{scene->yres_}
    , colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
    , filename_(file)
    , ppm_(width_, height_)*/
    scene_{scene},
    colorbuffer_(scene.xres_*scene.yres_, Color{}),
    ppm_(scene.xres_, scene.yres_, scene.filename)
    {}



//0.5 Alpha / 2 M_PI
void Renderer::render()
{

    float pic_ymax =2/scene_.xres_*scene_.yres_;

    float distance=1 /tan((scene_.camera.angle()*3.14159265)/180);
    std::cout <<"min. Distanz: " <<distance << "\n";
    int height_= scene_.yres_;
    int width_= scene_.xres_;

    float h = -height_/2;
    for (unsigned y = 0; y < height_; ++y) {
        //std::cout << y << "\n";


            float w = -width_/2;
        for (unsigned x = 0; x < width_; ++x) {

            glm::vec3 onedirection {w/(width_/2),h/(height_/2), -distance};
            Ray camray = scene_.camera.castray(onedirection);
//            Ray camray{scene_.camera.pos(), onedirection};
            Pixel p(x,y);
//            Hit hitteter=kugel.intersect(camray);
            Shape* first_hit;
            double shortest = 999999.9;

            for (std::vector<std::shared_ptr<Shape>>::iterator i = scene_.shapes_ptr.begin();i != scene_.shapes_ptr.end();++i){
                Hit hit = (*i)->intersect(camray);

                if(hit.hit_ == true){
                    if(hit.distance_ < shortest){
                        shortest = hit.distance_;
                        first_hit = hit.sptr_;
                        //std::cout <<"Normalvektor: " << hit.normal_.x <<", " << hit.normal_.y <<", " << hit.normal_.z  << "\n";

                        p.color = shade(camray, hit);
                        /*p.color = Color{
                            std::max(-1.0f, std::min(1.0f, hit.normal_.x)) / 2.0f + 0.5f,
                            std::max(-1.0f, std::min(1.0f, hit.normal_.y)) / 2.0f + 0.5f,
                            std::max(-1.0f, std::min(1.0f, hit.normal_.z)) / 2.0f + 0.5f
                        };*/
                    }
                }
            }

            if(shortest == 999999.9){
                p.color = scene_.background;
            }

/*            if(y == 1){
                if(x == 1){
                    p.color = {1.0,0.0,0.0};
                }
            }*/

            write(p);
            ++w;
        }
        ++h;
    }
    ppm_.save(scene_.filename);
    std::cout << "saved file in: " << scene_.filename << " amazing! \n";
//float pic_z =1/(0.5*1.0/*alpha*/);//alpha von der camera aus der scene "angle"
//glm::vec3 p1{-1.0,};
//  height_=(2/scene.width_);
//prinzipieller aufbau
    /*
while (int x = 0; x < width; ++x)
{
    for (int y = 0; y < height; ++y)
    {
        Pixel p(x,y,pic_z);
    }
}*/

//kurze Anmerkung: momentan bewegt sich der raytracer in 0,005er schritten von -1 an der x ache weiter bis zu 0,995 => es gibt 400 pixelspalten beginnend bei dem wert x= 1.0 bis zu x = 0,995 um das ganze exakt zu berechnen

//  const std::size_t checkersize = 20;

/*        float distance=(((scene_.camera.angle()/360)*2*3.1415)*0.5)/2*3.1415;
        glm::vec3 mittelp{0.0,0.0,-30.0};
        float rad = 1;
        Sphere kugel{mittelp, rad};
        glm::vec3 onedirection{0.0,0.0,-1.0};
        int height_= scene_.yres_;
        int width_= scene_.xres_;

        float h = height_/2;
    for (unsigned y = 0; y < height_; ++y) {
        //std::cout << y << "\n";


            float w = -width_/2;
        for (unsigned x = 0; x < width_; ++x) {
                //std::cout << "x = " << x << "\n";
            //
            // p.color = raytrace(ray, depth);
            glm::vec3 origin{w/(width_/2),h/(height_/2),0.0};
//      std::cout <<"origin vec " << origin.x << ", " << origin.y << ", " << origin.z << " \n";
            Ray camray{origin, onedirection};
            Pixel p(x,y);
            Hit hitteter=kugel.intersect(camray);
            if (hitteter.hit_ == true){
                p.color = Color(hitteter.normal_.x,hitteter.normal_.y,hitteter.normal_.z);
            } else{
                p.color = Color(0.0,0.0,0.0);
            }
            write(p);
            ++w;
        }
        --h;
    }
    ppm_.save(scene_.filename);
    std::cout << "saved file in: " << scene_.filename << " amazing! \n";*/
}

Color Renderer::shade(Ray const& ray, Hit const& hit){
    Color ka = hit.sptr_->getmaterial().ka;
    Color kd = hit.sptr_->getmaterial().kd;
    Color ks = hit.sptr_->getmaterial().ks;

    Color Ia = scene_.amblight;
    Color L_amb = Ia * ka;
    Color Id;
    Color L_diff_spec;
    Color L_gesamt;

    float angle1;
    float angle2;
    float shadowbias = 0.9f;

    std::vector<Color> Id_vec;
    std::vector<float> a1_vec;
    std::vector<float> a2_vec;

    glm::vec3 norm = glm::normalize(hit.normal_);
    glm::vec3 rref;
    glm::vec3 ray_inv_dir = glm::normalize(-ray.direction);
    // glm::vec3 ray_inv_dir = glm::normalize(ray.origin - hit.target_);


    for (std::vector<Light>::iterator i = scene_.lights.begin();i != scene_.lights.end();++i){
        glm::vec3 lightvec = glm::normalize(glm::vec3{ i->pos_ - hit.target_ });


        Ray lightray{hit.target_ + (shadowbias*norm), lightvec};
        std::cout << hit.normal_.x << " " << hit.normal_.y << " " << hit.normal_.z << std::endl;

            for (std::vector<std::shared_ptr<Shape>>::iterator j = scene_.shapes_ptr.begin();j != scene_.shapes_ptr.end();++j){
                Hit shadowhit = (*j)->intersect(lightray);

                if(shadowhit.hit_ && shadowhit.distance_ < sqrt(pow(lightvec.x, 2) + pow(lightvec.y, 2) + pow(lightvec.z,2))){
                    Id = {0.0,0.0,0.0};
                    angle1 = 0.0;
                    angle2 = 0.0;
                    //std::cout << "shadowhit distance_ " << shadowhit.distance_ << " < " << sqrt(pow(lightvec.x, 2) + pow(lightvec.y, 2) + pow(lightvec.z,2)) << std::endl;

                    break;
                }

                else{

                    Id = i->ld_;
                    angle1 = std::max(0.0f, glm::dot(norm, lightvec));

                    rref = 2.0f * angle1 * norm - lightvec;
                    angle2 = std::max(0.0f, glm::dot(rref, ray_inv_dir));

                }
            }

            Id_vec.push_back(Id);

            a1_vec.push_back(angle1);
            a2_vec.push_back(pow(angle2, hit.sptr_->getmaterial().m));

            Id = {0.0,0.0,0.0};
            angle1 = 0.0;
            angle2 = 0.0;
            lightvec = {0.0,0.0,0.0};

    }

    for(int t = 0; t < Id_vec.size(); ++t){
        L_diff_spec = L_diff_spec + (Id_vec[t]*((kd*a1_vec[t]) + (ks*a2_vec[t])));

    }

    L_gesamt = L_diff_spec + L_amb;


//    std::cout << L_gesamt;
    return L_gesamt;

}

void Renderer::write(Pixel const& p)
{
    // flip pixels, because of opengl glDrawPixels
    size_t buf_pos = (scene_.xres_*p.y + p.x);
    if (buf_pos >= colorbuffer_.size() || (int)buf_pos < 0) {
        std::cerr << "Fatal Error Renderer::write(Pixel p) : "
            << "pixel out of ppm_ : "
            << (int)p.x << "," << (int)p.y
            << std::endl;
    } else {
        colorbuffer_[buf_pos] = p.color;
    }
    //std::cout << scene_.xres_ << " " << scene_.yres_ << "\n";
    ppm_.write(p);
}
