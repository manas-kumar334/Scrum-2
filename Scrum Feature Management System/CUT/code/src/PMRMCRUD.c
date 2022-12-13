#include <stdio.h>
#include <logreg.h>
#include <stdlib.h>
#include <main.h>
#include <struct.h>
#include <bfeatures.h>

int displayFeatureBacklog(){
    /*Author: Divya Rathore
    Description: This Function will display all the Feature added by Product Manager into product backlog*/
    FILE *file;
    file = fopen("../data/featureBacklog.csv", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return EXIT_FAILURE;
    }

    Features features[max];
    int read = 0;
    int records = 0;
    do
    {
        read = fscanf(file, "%d,%49[^,],%d,%s\n", &features[records].featureid,  features[records].featureName, &features[records].priority, features[records].cost);

        if (read == 4)
            records++;

        if (read != 4 && !feof(file))
        {
            printf("File format incorrect\n");
            return EXIT_FAILURE;
        }

        if (ferror(file))
        {
            printf("Error Reading file\n");
            return EXIT_FAILURE;
        }
    } while (!feof(file));
    fclose(file);
    printf("There are total %d features\n--------------------------------------\n", records);
    for (int i = 0; i < records; i++)
    {
        printf("%d %s %d %s\n", features[i].featureid, features[i].featureName, features[i].priority, features[i].cost);
    }
    return EXIT_SUCCESS;
}

int displayFeatureRelease(){

    /*Author:Divya Rathore
    Description: This function will display all the Release Features selected by release manager*/
    FILE *fp1;
    fp1=fopen("../data/featureRelease.csv","r");
    if(fp1 == NULL){
        printf("Error Opening File.\n");
        return EXIT_FAILURE;
    }
    Features feature[max];
    uint_32 read=0;
    uint_32 records=0;
    do{
        read=fscanf(fp1,"%d,%s,%d,%s",&feature[records].featureid,feature[records].featureName,&feature[records].priority,feature[records].cost);
        if (read==4){
            records++;
        }
        if(read!=4 && !feof(fp1)){
            printf("Incorrect File Format\n");
            return EXIT_FAILURE;
        }
        if(ferror(fp1)){
            printf("Error Reading File\n");
            return EXIT_FAILURE;
        }
    }while (!feof(fp1));
    fclose(fp1);
    printf("Records Read is %d\n",records);
    for(int i=0;i<records;i++){
        printf("%d %s %d %s\n",feature[i].featureid,feature[i].featureName,feature[i].priority,feature[i].cost);
    }
    return EXIT_SUCCESS;
}

int importFeature(int choice){
    /*Author:Manas Behera
    Description:Importing Features from the Feature Backlog set by the product manager
    */
    FILE *file1, *file2;
    file1 = fopen("../data/featureBacklog.csv","r");
    file2 = fopen("../data/featureRelease.csv","a");
    if(file1==NULL){
        printf("ERROR OPENING FILE.\n");
        return EXIT_FAILURE;
    }
    Features features[max];
    uint_32 read=0;
    uint_32 records=0;
    do{
        read = fscanf(file1, "%d,%s,%d,%s\n",&features[records].featureid,features[records].featureName,&features[records].priority,features[records].cost);
        if(read==4)
            records++;
        if(read !=4 && !feof(file1)){
            printf("Incorrect File Format\n");
            return EXIT_FAILURE;
        }
        if(ferror(file1)){
            printf("Error Reading file.\n");
            return EXIT_FAILURE;
        }
    }while (!feof(file1));
    fclose(file1);
    printf("Records read is %d\n", records);
   // printf("FeatureID FeatureName Priority Cost");
    for(int i=0;i<records;i++){
        if(features[i].featureid==choice){
            fprintf(file2,"%d,%s,%d,%s\n",features[i].featureid,features[i].featureName,features[i].priority,features[i].cost);
            printf("Feature is successfully added to release list");
        }
    }
    fclose(file2);
    return EXIT_SUCCESS;

}

int addProductBacklog(){
    /*Author :Manas Behera
    Description:This function is for Product Manager to add Features into the backlog list
    */
    FILE *fp =fopen("../data/featureBacklog.csv","a+");
    uint_32 featureid;
    char featureName[max];
    uint_32 priority;
    char cost[cost_len];
    printf("\nEnter Feature ID\n");
    scanf("%d",&featureid);
    printf("\nEnter Feature Name\n");
    scanf("%s",featureName);
    printf("\nEnter Feature Priority\n");
    scanf("%d",&priority);
    printf("\nEnter Feature Shirt Size\n");
    scanf("%s",cost);
    fprintf(fp,"%d,%s,%d,%s",featureid,featureName,priority,cost);
    printf("Features are added successfully.\n");
    fclose(fp);
    return EXIT_SUCCESS;
}

int deleteBacklog(){
    /*Author Sakshi Verma
    Description:This method is to delete a particular Backlog feature which Product Owner wanted to delete
    */
    FILE *fp1;
    FILE *fp2;

    char ch;

    int line = 0;
    int temp = 1;

    fp1 = fopen("../data/featureBacklog.csv", "r");
    if (fp1 == NULL)
    {
        printf("\nUnable to open file\n");
        return -1;
    }

    while (!feof(fp1))
    {
        ch = getc(fp1);
    }
    rewind(fp1);

    printf("\nEnter line number to delete the features: ");
    scanf("%d", &line);

    fp2 = fopen("temp.csv", "w");

    while (!feof(fp1))
    {
        ch = getc(fp1);

        if (ch == '\n')
        {
            temp++;
        }
        if (temp != line)
        {
            putc(ch, fp2);
        }
    
    }

    fclose(fp1);

    fclose(fp2);

    remove("../data/featureBacklog.csv");
    rename("temp.csv", "../data/featureBacklog.csv");

    printf("\nFeature is deleted Successfully:\n");

    fp1 = fopen("../data/featureBacklog.csv", "r");
    if (fp1 == NULL)
    {
        printf("\nUnable to open file\n");
        return -1;
    }
    while (!feof(fp1))
    {
        ch = getc(fp1);
        // printf("%c", ch);
    }

    fclose(fp1);

    printf("\n");
    return EXIT_SUCCESS;
}
int deleteFeatures(){
    /*Author Sakshi Verma
    Description: This Function will delete the Release Features one by one if Release Manager want to remove/delete.*/
    FILE *fp1;
    FILE *fp2;

    char ch;

    int line = 0;
    int temp = 1;

    fp1 = fopen("../data/releaseFeatures.csv", "r");
    if (fp1 == NULL)
    {
        printf("\nUnable to open file\n");
        return -1;
    }

    while (!feof(fp1))
    {
        ch = getc(fp1);
    }
    rewind(fp1);

    printf("\nEnter line number to delete the features: ");
    scanf("%d", &line);

    fp2 = fopen("temp.csv", "w");

    while (!feof(fp1))
    {
        ch = getc(fp1);

        if (ch == '\n')
        {
            temp++;
        }
        if (temp != line)
        {
            putc(ch, fp2);
        }
    }
    fclose(fp1);

    fclose(fp2);

    remove("../data/releaseFeatures.csv");
    rename("temp.csv", "../data/releaseFeatures.csv");

    printf("\nModified features are:\n");

    fp1 = fopen("../data/releaseFeatures.csv", "r");
    if (fp1 == NULL)
    {
        printf("\nUnable to open file\n");
        return -1;
    }

    while (!feof(fp1))
    {
        ch = getc(fp1);
        
    }

    fclose(fp1);

    printf("\n");
    
    
    return EXIT_SUCCESS;
}

