#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
    public:
        Circle(float _x, float _y, int _radius);
        float getPosX();
        float getPosY();

        float getVelX();
        float getVelY();
        void setVelX(float x);
        void setVelY(float y);
        void setVel(float x, float y);

        float getAccX();
        float getAccY();
        void setAccX(float);
        void setAccY(float);

        void physStep(double deltatime);
        void setRadius(int radius);
        int getRadius(); 
    private:
        int radius;
        float x, y;
        float dx, dy;
        float ddx, ddy;

};

#endif //CIRCLE_H
