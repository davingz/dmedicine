#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char user[100];
int i,j,y,n;
char pass[100];
char dicari[100];

struct
{
	char usern[100],passwd[100],nama[100],alamat[100],no[100];
}member;

struct
{
	char nama[100],kategori[100],dosis[100],harga[100];
}obat,temp[100],temp2;

struct
{
	char viracc[100];
}rek;


void loginAdmin();
void menuAdmin();
void tambahObat();
void updateObat();
void hapusObat();
void VirAcc();
void tambahVirAcc();
void updtVirAcc();
void updtAkunMem();
void hapusAkun();
void info();
void infoMember();
void infoObat();
//---------------------------------
void menuAwalMember();
void regisMember();
void loginMember();
void menuMember();
void penyakit();
void milihObat();
void urutObat();
void metodeBayar();
void cod();
void bank();

FILE*f_dataMember;
FILE*f_obat;
FILE*f_dataVirAcc;

void main()
{
	system("cls");
    printf("\tWelcome to D'Medicine\n");
    puts("========================================\n");
    printf("Pilih Akun\n");
    printf("1. Admin\n");
    printf("2. Member\n");
    printf("Masukkan angka = ");scanf("%d",&i);getchar();
    switch(i)
	{
		case 1: loginAdmin();break;
		case 2: menuAwalMember();break;
	}
}

void loginAdmin()
{
	system("cls");
	n=3;
    printf("=======Silahkan Login=======\n");
    while(n>0)
	{
    	printf("User = ");gets(user);
    	printf("Pass = ");gets(pass);
	    if(strcmp(user, "admin")==0 && strcmp(pass, "admin")==0)
	    {
	    	printf("\nLogin berhasil!\n");
	    	menuAdmin();
	    }
	     else
	    {
	    	printf("\nUsername atau password salah silahkan coba lagi \n\n");n--;
	    }
	    if(n==0)
	    {
	    	printf("Sudah 3 kali salah, returning to main menu\n\n");main();
	    }
	}
		
}

void menuAdmin()
{
	system("cls");
	printf("*****************Welcome to D'Medicine*****************\n");
	printf("1. TAMBAH OBAT\n");
    printf("2. UPDATE OBAT\n");
    printf("3. HAPUS OBAT\n");
    printf("4. KODE VIRTUAL ACCOUNT\n");
    printf("5. UPDATE AKUN MEMBER\n");
    printf("6. HAPUS AKUN MEMBER\n");
    printf("7. INFO\n");
    printf("8. LOGOUT\n");
    printf("Pilih:  ");scanf("%d",&i);getchar();
    switch(i)
	{
		case 1: tambahObat();break;
		case 2: updateObat();break;
		case 3: hapusObat();break;
		case 4: VirAcc();break;
		case 5: updtAkunMem();break;
		case 6: hapusAkun();break;
		case 7: info();break;
		case 8: main();break;
	}
}


void tambahObat()
{
	system("cls");
	f_obat=fopen("file obat.dat","ab");
	printf("-------------Tambah Obat-------------\n"); 
	printf("Banyak obat Yang Mau Diinput: "); 
	scanf("%d", &n); getchar(); 
	for (i=1; i<=n; i++)
	{ 
		printf("\nNama  : "); 
		gets(obat.nama); 
		printf("Harga : ");
		gets(obat.harga);
		printf("Kategori: "); 
		gets(obat.kategori); 
		printf("Dosis : ");  
		gets(obat.dosis); 
		fwrite(&obat,sizeof(obat),1,f_obat);
	} 
	printf("Data Obat sudah tersimpan\t");
	system("pause");
 	fclose(f_obat); 
 	menuAdmin(); 
}

void updateObat()
{
		system("cls");
	printf("#################Update Obat#################\n");
	f_obat=fopen("file obat.dat","rb");

	while(fread(&obat,sizeof(obat),1,f_obat)==1)
	{
		printf("\n\tNama\t : %s ",obat.nama);
		printf("\n\tHarga\t : %s ",obat.harga);
		printf("\n\tKategori\t : %s ", obat.kategori);
		printf("\n\tDosis\t : %s ", obat.dosis);
		printf("\n\n");
	}
	fclose(f_obat);
	
	printf("#################Masukkan nama yang mau diupdate#################\n : ");
	fflush(stdin);
	gets(dicari);
	
	f_obat=fopen("file obat.dat","rb+");
	while(fread(&obat,sizeof(obat),1,f_obat)==1)
	{
		if(strcmp(obat.nama,dicari)==0)
		{
			fseek(f_obat,-sizeof(obat),SEEK_CUR);
			printf("\nNama\n  : ");gets(obat.nama); 
			printf("Harga\n : ");gets(obat.harga);
			printf("Kategori\n: "); gets(obat.kategori); 
			printf("Dosis \n: "); gets(obat.dosis); 
			printf("\n\n");
			fwrite(&obat,sizeof(obat),1,f_obat);
			break;
		}
	}
	fclose(f_obat);
	system("pause");
	menuAdmin();
}

void hapusObat()
{

	system("cls");
	FILE *f_obat2;
	f_obat=fopen("file obat.dat","rb");
	f_obat2=fopen("file obat2.dat","wb");
	printf("Silahkan Masukan Nama Obat Yang Mau Dihapus : "); fflush(stdin);gets(dicari);
	while (fread(&obat,sizeof(obat),1,f_obat)==1)
	{
		if (strcmp(obat.nama, dicari)!=0)
		{
			fwrite(&obat,sizeof(obat),1,f_obat2);
		}
	}
		fclose(f_obat);
		fclose(f_obat2);
		remove("file obat.dat");
		rename("file obat2.dat","file obat.dat");
	menuAdmin();

}

void VirAcc()
{
	system("cls");
	printf("Menu Virtual Account...\n");
    printf("1. Tambah\n");
    printf("2. Update\n");
    printf("3. Kembali\n");
	printf("Pilih menu \n");scanf("%d",&i);getchar();
    switch(i)
	{
		case 1: tambahVirAcc();break;
		case 2: updtVirAcc();break;
		case 3: menuAdmin();break;
	}
}

void tambahVirAcc()
{
	system("cls");
	printf("INPUT VIRTUAL ACCOUNT\n");
		f_dataVirAcc=fopen("data VirtualAcc.dat","ab"); 
	printf("\tVirtual Account\t:"); gets(rek.viracc);
	printf("Data sudah tersimpan :)\n");
	
	fwrite(&rek, sizeof(rek), 1,f_dataVirAcc); 	
	fclose(f_dataVirAcc);
	system("pause");
	menuAdmin();
	
}

void updtVirAcc()
{
	system("cls");
	printf("Update Virtual Account\n");
	f_dataVirAcc=fopen("data VirtualAcc.dat","rb");

	while(fread(&rek,sizeof(rek),1,f_dataVirAcc)==1)
	{
		printf("\n\tNomor Virtual Account\t : %s ",rek.viracc);
		printf("\n\n");
	}
	fclose(f_dataVirAcc);
	
	printf("Kode Virtual Yang diupdate : ");
	fflush(stdin);
	gets(dicari);
	
	f_dataVirAcc=fopen("data VirtualAcc.dat","rb+");
	while(fread(&rek,sizeof(rek),1,f_dataVirAcc)==1)
	{
		if(strcmp(rek.viracc,dicari)==0)
		{
			fseek(f_dataVirAcc,-sizeof(rek),SEEK_CUR);
			printf("\tNomor Virtual Account \t:"); gets(rek.viracc);
			printf("\n\n");
			fwrite(&rek,sizeof(rek),1,f_dataVirAcc);
			break;
		}
	}
	fclose(f_dataVirAcc);
	system("pause");
	menuAdmin();
}

void updtAkunMem()
{
	system("cls");
	printf("Update Akun Member\n");
	f_dataMember=fopen("data member.dat","rb");

	while(fread(&member,sizeof(member),1,f_dataMember)==1)
	{
		printf("\n\tUserName\t : %s ",member.usern);
		printf("\n\tNama\t : %s ",member.nama);
		printf("\n\tNo Hp\t : %s ", member.no);
		printf("\n\tAlamat\t : %s ", member.alamat);
		printf("\n\n");
	}
	fclose(f_dataMember);
	
	printf("Masukkan nama yang mau diupdate : ");
	fflush(stdin);
	gets(dicari);
	
	f_dataMember=fopen("data member.dat","rb+");
	while(fread(&member,sizeof(member),1,f_dataMember)==1)
	{
		if(strcmp(member.nama,dicari)==0)
		{
			fseek(f_dataMember,-sizeof(member),SEEK_CUR);
			printf("\tUsername \t:"); gets(member.usern);
			printf("\tPassword\t:"); gets(member.passwd);
			printf("\tNama\t:"); gets(member.nama);
			printf("\tAlamat\t:"); gets(member.alamat);
			printf("\tNo.HP\t:"); gets(member.no);
			printf("\n\n");
			fwrite(&member,sizeof(member),1,f_dataMember);
			break;
		}
	}
	fclose(f_dataMember);
	system("pause");
	menuAdmin();
}

void hapusAkun()
{

	system("cls");
	FILE *f_dataMember2;
	f_dataMember=fopen("data member.dat","rb");
	f_dataMember2=fopen("data member2.dat","wb");
	printf("Silahkan Masukan UserName Member Yang Mau Dihapus : "); fflush(stdin);gets(dicari);
	while (fread(&member, sizeof(member), 1,f_dataMember)==1)
	{
		if (strcmp(member.usern, dicari)!=0)
		{
			fwrite(&member, sizeof(member), 1,f_dataMember2);
		}
	}
		fclose(f_dataMember);
		fclose(f_dataMember2);
		remove("data member.dat");
		rename("data member2.dat","data member.dat"); 
	menuAdmin();

}

void info()
{
		system("cls");
	printf("\tSegala Info Tentang...\n");
	printf("1. Member\n");
    printf("2. Obat\n");
    printf("3. Kembali\n");
    printf("Pilih:  ");scanf("%d",&i);getchar();
	switch(i)
	{
		case 1: infoMember();break;
		case 2: infoObat();break;
		case 3: menuAdmin();break;
	}
}

void infoMember()
{
	system("cls");
	f_dataMember=fopen("data member.dat","rb"); 
	printf("Info Member\n");
	while(fread(&member, sizeof(member), 1,f_dataMember)==1)
	{
		printf("\n\tUserName\t : %s ",member.usern);
		printf("\n\tNama\t : %s ",member.nama);
		printf("\n\tNo Hp\t : %s ", member.no);
		printf("\n\tAlamat\t : %s ", member.alamat);
		printf("\n\n");
	}
	fclose(f_dataMember);
	system("pause");
	info();
}

void infoObat()
{
	system("cls");
	f_obat=fopen("file obat.dat","rb"); 
	printf("Info Obat Tersedia\n");
	while(fread(&obat, sizeof(obat), 1,f_obat)==1)
	{
		printf("\n\tNama\t : %s ",obat.nama);
		printf("\n\tHarga\t : %s ",obat.harga);
		printf("\n\tKategori\t : %s ", obat.kategori);
		printf("\n\tDosis\t : %s ", obat.dosis);
		printf("\n\n");
	}
	fclose(f_obat);
	system("pause");
	info();
}


void menuAwalMember()
{
	system("cls");
	printf("Menu Member\n");
    printf("1. Login\n");
    printf("2. Regis\n");
    printf("3. Kembali\n");
	printf("Pilih menu \n");scanf("%d",&i);getchar();
    switch(i)
	{
		case 1: loginMember(3);break;
		case 2: regisMember();break;
		case 3: main();break;
	}
}

void regisMember()
{
	system("cls");
	printf("INPUT DATA MEMBER\n");
		f_dataMember=fopen("data member.dat","ab"); 
	printf("\tUsername \t:"); gets(member.usern);
	printf("\tPassword\t:"); gets(member.passwd);
	printf("\tNama\t:"); gets(member.nama);
	printf("\tAlamat\t:"); gets(member.alamat);
	printf("\tNo.HP\t:"); gets(member.no);
	printf("Data sudah tersimpan silahkan Login Kembali :)\n");
	
	fwrite(&member, sizeof(member), 1,f_dataMember); 	
	fclose(f_dataMember);
	system("pause");
	menuAwalMember();
}

void loginMember(int n)
{

	system("cls");
	printf("=======Silahkan Login=======\n");
	printf("User = ");gets(user);
    printf("Pass = ");gets(pass);
   	f_dataMember=fopen("data member.dat","rb"); 
   	y=0;
       
 	while(fread(&member,sizeof(member),1,f_dataMember)==1)
		{
    	
	    if(strcmp(user, member.usern)==0 && strcmp(pass,member.passwd)==0)
	    	{
				y=1;
				break;
	   		}
		}
	fclose(f_dataMember);
 
	if(y==1)
		{
		
		    printf("\nLogin berhasil!");
			getchar();
		    menuMember();
	    
		}
	else 
		{
			printf("\nUsername atau password salah silahkan coba lagi\n");
			n--;
			getchar();
			if(n>0)
				{
					loginMember(n);
				
				}
			else 
				{
					printf("Anda sudah 3 kali salah, returning to main menu\n\n");
					getchar;
					system("pause");
					main();
				}
			system("cls");
		}
}

void menuMember()
{
	system("cls");
	printf("\tWelcome to D'Medicine\n");
    printf("1. Beli Obat\n");
    printf("2. Keluar\n");
    printf("Pilih:  ");scanf("%d",&i);getchar();
    switch(i)
	{
		case 1: penyakit();break;
		case 2: main();break;
	}
}

void penyakit() //Menu Untuk member memilih kategori Obat
{
	system("cls");
	f_obat=fopen("file obat.dat","rb");
	i=0;
	printf("Apa Penyakit Yang Anda Alami?\n");
	printf("-Demam\n");
	printf("-Pusing\n");
	printf("-Covid\n");
	printf("-Flu\n");
	
	f_obat=fopen("file obat.dat","rb");
	printf("Tulis Nama Penyakit : ");
	gets(dicari);
	while(fread(&obat,sizeof(obat),1,f_obat)==1)
	{
		if(strcmp(obat.kategori,dicari)==0)
		{
			urutObat();
			break;
		}
	}
	fclose(f_obat);
}

void urutObat()
{
	f_obat=fopen("file obat.dat","rb");
	i=0;
	j=0; 
	y=1;
	while(fread(&obat,sizeof(obat),1,f_obat)==1)
	{
		strcpy(temp[i].nama,obat.nama);
		strcpy(temp[i].kategori,obat.kategori);
		strcpy(temp[i].dosis,obat.dosis);
		strcpy(temp[i].harga,obat.harga);
		i++;
		y++;
	}
	fclose(f_obat);
	for(i=y-1;i>=1;i--)
	{
    	for(j=1;j<=i;j++)
		{
           	if(strcmp(temp[j].nama,temp[j-1].nama)<0)
			   {               	
					temp2=temp[j-1];
               		temp[j-1]=temp[j];
               		temp[j]=temp2;
            	}
        }
	}
	for(i=0;i<=y;i++)
	{
		if(strcmp(temp[i].kategori,dicari)==0)
		{
			printf("\tNama obat\t\t : %s ", temp[i].nama);
			printf("\n\tDosis (mg)\t\t : %s ", temp[i].dosis);
			printf("\n\tKategori\t\t : %s ", temp[i].kategori);
			printf("\n\tHarga\t\t\t : %s", temp[i].harga);
			printf("\n\n");
		}
	}
	milihObat();
}

void milihObat()//Menu untuk member memilih obat
{
	f_obat=fopen("file obat.dat","rb");
	printf("Tulis Nama Obat : ");
	gets(dicari);
	while(fread(&obat,sizeof(obat),1,f_obat)==1)
	{
		if(strcmp(obat.nama,dicari)==0)
		{
			metodeBayar();
		}
	}
	fclose(f_obat);
	
}

void metodeBayar()
{
	system("cls");
	printf("\tPilih Metode Pembayaran\n");
    printf("1. COD\n");
    printf("2. VIA BANK\n");
    printf("Pilih:  ");scanf("%d",&i);getchar();
    switch(i)
	{
		case 1: cod();break;
		case 2: bank();break;
	}
	
}

void cod()
{
	printf("\tObat Akan Segera dikirim\n");
	system("pause");
	main();
}

void bank()
{

	system("cls");
	printf("Pembayaran Transfer Dengan Virtual Account\n");
	f_dataVirAcc=fopen("data VirtualAcc.dat","rb");
	printf("Silahkan Bayar Ke Nomor Rekening Virtual Dibawah Ini \n\n");
		while(fread(&rek,sizeof(rek),1,f_dataVirAcc)==1)
	{
		printf("\n\n");
	}
	f_dataMember=fopen("data member.dat","rb");
	printf("Tulis Nama Anda : ");
	fflush(stdin);
	gets(dicari);
	
		while(fread(&member,sizeof(member),1,f_dataMember)==1)
	{
		if(strcmp(member.nama,dicari)==0)
		{
			fseek(f_dataMember,-sizeof(member),SEEK_CUR);
			printf("\n\tNo Rekening\t : %s%s\n\n",rek.viracc, member.no);
			printf("Terima Kasih Sudah Berbelanja \n");
			printf("Semoga Cepat Sembuh\n");
			break;
		}
	}
	fclose(f_dataMember);
	fclose(f_dataVirAcc);
	system("pause");
	main();

}
