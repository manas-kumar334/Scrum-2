/*
main.h contains all declaration of methods
*/

#ifndef __MAIN_H__
#define __MAIN_H__ 1

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1


//declaration of functions
extern int ProductManagerLogin(); //Login function for Product Manager Akanksha
extern int ProductManagerRegistration();//Registration Function for Product Mananger Santipriya
extern int ReleaseManagerLogin();//Login function for Release Manager Akanksha
extern int ReleaseManagerRegistration();//Registration Function for Release Mananger Santipriya
extern int displayFeatureBacklog();//Display Feature Backlog as a Product Owner Divya
extern int displayFeatureRelease();//Display Feature Backlog as a Release Manager Divya
extern int importFeature(int choice);//Import/Select Feature from Backlog as a Release manager Manas
extern int addProductBacklog();//Add Feature Backlog as a Product Owner LL Sakshi
extern int deleteBacklog();//Delete Feature Backlog as a Product Owner  LL Sakshi
extern int deleteFeatures();//Delete Feature Backlog as a Release Manager LL Manas

#endif

