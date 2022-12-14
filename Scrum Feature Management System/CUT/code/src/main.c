/****************************************************************************************************************************************************
*                                                           SCRUM FEATURE MANAGEMENT SYSTEM                                                         *                                                                                         *
*This is the main function. This function has the menu system where many functions are called.                                                      *
*Team Members: Akanksha Singh,Divya Rathore,Sakshi Verma,Santipriya Bodeboina.                                                                      *
*Made by Manas Kumar Behera. on 9th December 2022.                                                                                                  *
*****************************************************************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <bfeatures.h>
#include <logreg.h>
#include <stdlib.h>
int main()
{    //This is main function
    
    printf("\n*******************************************************************************************************\n");
    printf("\n*                          WELCOME TO SCRUM FEATURE MANAGEMENT SYSTEM                                 *\n");
    printf("\n*******************************************************************************************************\n");
    printf("\n");
    printf("Press 1 to Login/Register as Product Manager\nPress 2 to Login/Register as Release Manager\n");
    uint_32 choice;
    scanf("%d",&choice);

    if (choice==1)
    {
        uint_32 choice1;
        printf("\n********************PRODUCT MANAGER*********************\n");
        printf("\nPress 1 to Register\n");
        printf("\nPress 2 to Login\n");
        scanf("%d",&choice1);
        if(choice1 == 1)
	{
            ProductManagerRegistration();
        }
        else if(choice1==2)
	{
            uint_32 n;
            n=ProductManagerLogin();
            if(n==1)
	    {
                while(1)
		{
                    printf("-------------------SELECT CHOICE---------------------------\n1. Add Features into Product Backlog.\n2. Delete Features from Product Backlog.\n3.Display Features of Product Backlog.\n4.Exit.\n---------------------------------------------------------------\n");
                    uint_32 n=0;
                    scanf("%d",&n);

                    switch(n)
		    {
                        case 1:
                            addProductBacklog();
                            break;
                        case 2:
                            deleteBacklog();
                            break;
                        case 3:
                            displayFeatureBacklog();
                            break;
                        case 4:
                            exit(0);
                    
                    }

                }
            }
        }


    }
    else if(choice==2)
    {
        printf("\n*************************************************RELEASE MANAGER*************************************************\n");
        uint_32 choice2;
        printf("\nPress 1 to Register\n");
        printf("\nPress 2 to Login\n");
       	printf("\n");
	scanf("%d",&choice2);
        if (choice2==1){
            ReleaseManagerRegistration();
        }
        else if (choice2==2){
            uint_32 n;
            n=ReleaseManagerLogin();

            if(n==1){
                while(1){
                    printf("------------------SELECT CHOICE------------------------\n1.Add Features .\n2.Display all Release Features.\n3.Delete.\n4Exit.\n---------------------------------------------------------------\n");
                    uint_32 choice;
                    scanf("%d",&choice);
                    switch (choice){
                    case 1:
                        printf("Choose features to be implemented from given list\n");
                        displayFeatureBacklog();
                        printf("--------------------------\nEnter the feature ID to add to Release List: \n");
                        scanf("%d",&choice);
                        importFeature(choice);
                        break;
                    case 2:
                        displayFeatureRelease();
                        break;
                    case 3:
                        deleteFeatures();
                        break;
                    case 4:
                        exit(0);
                    }
                }
            }
        }


    }
    return EXIT_SUCCESS;
}    
