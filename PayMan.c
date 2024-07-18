#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 4096
#define ORI 256

typedef struct {
	char name[100];
    char pass[100];
    char telp[24];
} Users;

typedef struct {
    char id[1000];
    char name[100];
    int quantity;
    double price;
} Item;

int main ()
{
	int opsi, a=0;
	bool acc = false;
	char buffer[ORI];
    Users user;
	FILE *pFa = fopen("user.txt", "a");
	FILE *pFr = fopen("user.txt", "r");

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
			"Selamat datang di Min-POS\n"
            "~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("1.Daftar \n2.Masuk \n");

	while(1)    /*Selection for "sign in or log in"*/
    {
		printf("No:");
        fgets(buffer, ORI, stdin);
        if (sscanf(buffer, " %d", &opsi) == 1)
        {
            break;
        }else
        {
            printf("coba lagi\n");
        }
    }

	switch(opsi)
	{
		case 1 :    printf("Nama lengkap:");
					fgets(user.name, 100, stdin);
					printf("Nomor telpon:");
					fgets(user.telp, 24, stdin);
					printf("Sandi:");
					fgets(user.pass, 100, stdin);

					fputs("~ ~ ~ ~ ~\n", pFa);
					fputs(user.name, pFa);
					fputs(user.pass, pFa);
					fputs(user.telp, pFa);
                    fclose(pFa);
                    break;

		case 2 : 	printf("Nama lengkap:");
					fgets(user.name, 100, stdin);
					printf("Sandi: ");
					fgets(user.pass, 100, stdin);

					rewind(pFr);    //Searching the data from bases
					while(fgets(buffer, ORI, pFr) != NULL)
                    {
                        if (!strcmp(buffer, user.name))
                        {
                            fgets(buffer, ORI, pFr);
                            if (!strcmp(buffer, user.pass))
                            {
                                printf("Sukses");
                                acc = 1;
                                break;
                            }
                        }
                    }
                    if (acc != 1)
                    {
                        printf("Gagal");
                    }
                    fclose(pFr);
					break;
	}

	return 0;
}

