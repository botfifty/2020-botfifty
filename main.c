#include <kipr/wombat.h>
//there is no place for the claw itself to open?
void forward(int distance);
void backward(int distance);
void right(int degrees);
void left(int degrees);
int main()
{
    create_connect();
    enable_servos();
    set_servo_position(0,500);//open
    
    int x=0;
    forward(60);
    left(45);
// rasies up claw
    cmpc(0);
    while(gmpc(0)<8000)
    {
        mav(0,500);
    }
    ao();
    msleep(1000);
//find botball
/*    camera_open_black();
    while(x < 1)
    {
        camera_update();
        while (get_object_center_x(0,0)<80)
        {
           left(2.5); 
           camera_update();
           msleep(500);
            
        }
        while (get_object_center_x(0,0)>80)
        {
          	right(2.5);
			camera_update();
            msleep(500);
        }
        if (get_object_center_x(0,0)==80)
        {
            x=x+1;
        }
    }*/
//found him! 
//Drive forward 
//    while(get_create_rbump()==0)
//    {
//        create_drive_direct(250,250);
//    }
    forward(60);
    set_servo_position(0,1500);
    mav(0,500);
    msleep(500);
    ao();
    backward(15);
    left(180);
   while(gmpc(0)>1000)
    {
        mav(0,-500);
    }
    ao();
    set_servo_position(0,500);
    while ( get_create_rfcliff_amt()>2200)
    {
        create_drive_direct(250,250);
    }
	right(45);
    //drive to ball
    //while((get_create_rbump()==0)&&(get_create_lbump()==0))
    //{
       // create_drive_direct(250,250);
   // }
    forward(40);
    //grab ball
    set_servo_position(0,1500);
    left(200);
    // raise claw up
    cmpc(0);
    while(gmpc(0)<8000)
    {
        mav(0,500);
    }
    ao();
    msleep(1000);
    //drive to mountain
    forward(50);
    set_servo_position(0,500);
   
    disable_servos();
    create_stop();
    create_disconnect();
    return 0;
}
void forward(int distance)
{
    create_drive_direct(250, 250);
    msleep(distance/25*1000);
    create_stop();
}
void backward(int distance)
{
    create_drive_direct(-250,-250);
    msleep(distance/25*1000);
    create_stop();
}
void right(int degrees)
{
    create_drive_direct(150,-150);
    msleep(degrees*14.5);
    create_stop();
}
void left(int degrees)
{
    create_drive_direct(-150,150);
    msleep(degrees*14.5);
    create_stop();
}
