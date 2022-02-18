#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct point {
    int x,y;
};
struct rectangle {
    struct point upper_left,lower_right;
};

int rectangle_area(struct rectangle r){
    int height = r.upper_left.y-r.lower_right.y;
    int width = r.lower_right.x-r.upper_left.x;
    int A = abs(height*width);
    return A;
}

struct point find_center(struct rectangle r){
    struct point center;
    int mid_y = (int)(r.upper_left.y+r.lower_right.y)/2;
    int mid_x = (int)(r.lower_right.x+r.upper_left.x)/2;
    center.x = mid_x;
    center.y = mid_y;
    return center;
}

struct rectangle move_rectangle(struct rectangle r,int x, int y){
    struct point newUL = {r.upper_left.x+x,r.upper_left.y+y};
    struct point newLR = {r.lower_right.x+x,r.lower_right.y+y};
    struct rectangle r2 = {newUL,newLR};
    return r2;
}

bool point_in_rectangle(struct rectangle r,struct point p){
    if(p.x<=r.lower_right.x && p.x>=r.upper_left.x &&p.y<=r.upper_left.y && p.y>=r.lower_right.y){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    struct point ul1={0,4};
    struct point lr1={4,0};
    struct rectangle r1 = {ul1,lr1};
    int A = rectangle_area(r1);
    struct point midtpunkt = find_center(r1);
    struct rectangle r2 = move_rectangle(r1,700,2);
    struct point center2 = find_center(r2);
    printf("Area %d",A);
    printf("\nCenter is in {%d,%d}",midtpunkt.x,midtpunkt.y);
    printf("\nRectangle ul %d,%d, lr %d,%d",r2.upper_left.x,r2.upper_left.y,r2.lower_right.x,r2.lower_right.y);
    printf("\nMoved rectangle has center in {%d,%d}",center2.x,center2.y);
    struct point checker ={704,2};
    bool isInside = point_in_rectangle(r2,checker);
    if(isInside){printf("\npoint is inside");}
    else{printf("\npoint is outside");}
    
    return 0;
}