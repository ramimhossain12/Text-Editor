#include<stdio.h>
#include<conio.h>

int i,j,ch;
char fn[0],e,c;
FILE *fp1,*fp2,*fp;

void open_a_text_File();
void Edit_File();
void Save();
void Delete();
void Read_File();

int main() {
    while(1) {
        printf("\n\t\t***** TEXT EDITOR *****");
        printf("\n\n\tMENU:\n\t\n");
        printf("\n\t1.open_a_text_File\n\t2.Read_File\n\t3.Edit_File\n\t4.Save\n\t5.DELETE\n\t6.EXIT\n");
        printf("\n\tEnter your choice: ");
        scanf("%d",&ch);
        if(ch==1){
            open_a_text_File();
        }
        else if(ch==2){
            Read_File();
        }
        else if (ch==3){
            Edit_File();
        }
       else if (ch==4){
            Save();
       }
       else if(ch==5){
            Delete();
       }
       else if(ch==6){
            return 0;
        }
       else{
        printf("Invalid Number\n");
       }
    }
}

void open_a_text_File() {
    fp1 = fopen("temp.txt","w");
    printf("\n\tEnter the text and press '.' to save\n\n\t");
    while(1) {
        c = getchar();
        fputc(c,fp1);
        if(c == '.') {
            fclose(fp1);
            break;
        }
    }
}
void Read_File() {
    printf("\n\tEnter the file name: ");
    scanf("%s",fn);
    fp1=fopen(fn,"r");
    if(fp1 == NULL) {
        printf("\n\tFile not found!");
        goto end1;
    }
    while(!feof(fp1)) {
        c=getc(fp1);
        printf("%c",c);
    }
end1:
    fclose(fp1);
    printf("\n\n\tPress any key to continue\n");
}
void Save() {
    printf("\n\tEnter the new file name to copy:  ");
    scanf("%s",fn);
    fp1=fopen("temp.txt","r");
    fp2=fopen(fn,"w");
    while(!feof(fp1)) {
        c=getc(fp1);
        putc(c,fp2);
    }
    fclose(fp2);
}

void Delete() {
    printf("\n\tEnter the file name: ");
    scanf("%s",fn);
    fp1=fopen(fn,"r");
    if(fp1==NULL) {
        printf("\n\tFile not found!");
        goto end2;
    }
    fclose(fp1);
    if(remove(fn)==0) {
        printf("\n\n\tFile has been deleted successfully!");
        goto end2;
    } else
        printf("\n\tError!\n");
end2:
    printf("\n\n\tPress any key to continue\n");

}

void Edit_File() {
    printf("\n\tEnter the file name: ");
    scanf("%s",fn);
    fp1=fopen(fn,"r");
    if(fp1==NULL) {
        printf("\n\tFile not found!");
        fclose(fp1);
        goto end3;
    }
    while(!feof(fp1)) {
        c=getc(fp1);
        printf("%c",c);
    }
    fclose(fp1);
    printf("\n\tType the text and press Ctrl+S to append.\n");
    fp1=fopen(fn,"a");
    while(1) {
        c=getch();
        if(c==19)
            goto end3;
        if(c==13) {
            c='\n';
            printf("\n\t");
            fputc(c,fp1);
        } else {
            printf("%c",c);
            fputc(c,fp1);
        }
    }
end3:
    fclose(fp1);
}
