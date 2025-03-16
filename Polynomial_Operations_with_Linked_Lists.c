#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct Dugum 
{
    int katsayi;
    int derece;
    struct Dugum* sonraki;
};

struct Dugum* yeniDugumOlustur(int katsayi, int derece) 
{
    struct Dugum* dugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    if (dugum == NULL) 
    {
        printf("Bellek Yetersiz!!!\n");
        exit(1);
    }
    dugum->katsayi = katsayi;
    dugum->derece = derece;
    dugum->sonraki = NULL;
    return dugum;
}

void SiraliEkle(struct Dugum** bas_referans, int katsayi, int derece) 
{
    struct Dugum* yeni_dugum = yeniDugumOlustur(katsayi, derece);
    if (*bas_referans == NULL) 
    {
        *bas_referans = yeni_dugum;
        return;
    }
    struct Dugum* iter = *bas_referans;
    struct Dugum* onceki = NULL;
    while (iter != NULL && iter->derece > derece) 
    {
        onceki = iter;
        iter = iter->sonraki;
    }
    if (onceki == NULL) 
    {
        yeni_dugum->sonraki = *bas_referans;
        *bas_referans = yeni_dugum;
    } 
    else 
    {
        onceki->sonraki = yeni_dugum;
        yeni_dugum->sonraki = iter;
    }
}

void listeyiYazdir(struct Dugum* dugum)
{
    struct Dugum* iter = dugum;
    while (iter != NULL) 
    {
        if(iter->katsayi==1)
        {
        	if(iter->sonraki == NULL)
        	{
        		printf("X%d",iter->derece);
			}
			else
			{
				printf("X%d + ",iter->derece);
			}
        }
        else if(iter->derece==0)
        {
        	if(iter->sonraki == NULL)
        	{
        		printf("%d",iter->katsayi);
			}
			else
			{
				printf("%d + ",iter->katsayi);
			}
        }
        else if(iter->derece==1)
        {
        	if(iter->sonraki == NULL)
        	{
        		printf("%dX",iter->katsayi);
			}
			else
			{
				printf("%dX + ",iter->katsayi);
			}
        }
        else
        {
        	if(iter->sonraki == NULL)
        	{
        		printf("%dX%d", iter->katsayi, iter->derece);	
			}
			else
			{
				printf("%dX%d + ", iter->katsayi, iter->derece);
			}
        }
        iter = iter->sonraki;
    }
    printf("\n");
}

void temizle(struct Dugum** bas_referans) 
{
    struct Dugum* temp;
    while (*bas_referans != NULL) 
    {
        temp = *bas_referans;
        *bas_referans = (*bas_referans)->sonraki;
        free(temp);
    }
}

double hesapla(struct Dugum* polinom, double x)
{
    double sonuc = 0.0;
    struct Dugum* iter = polinom;
    while (iter != NULL) 
    {
        sonuc += iter->katsayi * pow(x, iter->derece);
        iter = iter->sonraki;
    }
    return sonuc;
}

void Polinomdan_Eleman_Sil(struct Dugum** bagliListe, int derece)
{
    struct Dugum* temp = (*bagliListe) -> sonraki;
    struct Dugum* iter = (*bagliListe);

    if(*bagliListe == NULL)
    {
        printf("Polinom Boþ");
    }
    else if((*bagliListe) -> derece == derece)
    {
        free(*bagliListe);
        (*bagliListe) = temp;
    }
    else
    {
        while(iter != NULL && iter -> derece != derece)
        {
            temp = iter;
            iter = iter -> sonraki;
        }

        if(iter == NULL)
        {
            printf("Istenen Eleman Bulunamadi!\n");
        }
        else
        {
            temp -> sonraki = iter -> sonraki;
            free(iter);
        }
    }
}

struct Dugum* PolinomTopla(struct Dugum* polinom1, struct Dugum* polinom2)
{
    struct Dugum* sonuc = NULL;
    struct Dugum* iter1 = polinom1;
    struct Dugum* iter2 = polinom2;

    while (iter1 != NULL && iter2 != NULL)
    {
        if (iter1->derece == iter2->derece)
        {
            SiraliEkle(&sonuc, iter1->katsayi + iter2->katsayi, iter1->derece);
            iter1 = iter1->sonraki;
            iter2 = iter2->sonraki;
        }
        else if (iter1->derece > iter2->derece)
        {
            SiraliEkle(&sonuc, iter1->katsayi, iter1->derece);
            iter1 = iter1->sonraki;
        }
        else
        {
            SiraliEkle(&sonuc, iter2->katsayi, iter2->derece);
            iter2 = iter2->sonraki;
        }
    }

    while (iter1 != NULL)
    {
        SiraliEkle(&sonuc, iter1->katsayi, iter1->derece);
        iter1 = iter1->sonraki;
    }

    while (iter2 != NULL)
    {
        SiraliEkle(&sonuc, iter2->katsayi, iter2->derece);
        iter2 = iter2->sonraki;
    }

    return sonuc;
}


int main() 
{
    srand(time(NULL));
    
    int secim;
    struct Dugum* bas1 = NULL;
    struct Dugum* bas2 = NULL;
    int N;
    int katsayi1[7];
    int derece1[7];
    int katsayi2[7];
    int derece2[7];
    int temp_derece1[7], temp_katsayi1[7], temp_derece2[7], temp_katsayi2[7], kontrol;
    double x;
    int silinecekDerece;
    struct Dugum* toplam = NULL; 

	printf("1-Polinomlari Rastgele Uret ve Bagli Listeyi Olustur\n");
	printf("2-Listele (Polinomal Sekilde goster)\n");
	printf("3-x Degerine Gore Hesapla\n");
	printf("4-Polinom Derecesine Gore Sil\n");
	printf("5-Polinom Topla\n");
	printf("6-Cikis\n");
	
    while(1) 
    {   
        printf("Secim yapiniz--->");
        scanf("%d",&secim);
        switch(secim) {
            case 1:
                temizle(&bas1);
                temizle(&bas2);
                printf("Polinomlar kac elemanli olsun--->");
                scanf("%d", &N);

                if (N > 7) 
                {
                    printf("Dereceler farkli olacagindan dolayi polinom max 7 elemanli olabilir!!!\n");
                    break;
                }

                int sayac1 = 0;
                int temp1 = N;

                while (temp1 > 0) 
                {
                    int kontrol;
                    do 
                    {
                        kontrol = 1;
                        katsayi1[sayac1] = rand() % 11;
                        derece1[sayac1] = rand() % 7;

                        for (int i = 0; i < sayac1; i++) 
                        {
                            if (katsayi1[sayac1] == temp_katsayi1[i] || derece1[sayac1] == temp_derece1[i]) 
                            {
                                kontrol = 0;
                                break;
                            }
                        }
                    }while (kontrol == 0);

                    temp_katsayi1[sayac1] = katsayi1[sayac1];
                    temp_derece1[sayac1] = derece1[sayac1];
                    sayac1++;
                    temp1--;
                }

                for (int i = 0; i < sayac1; i++) 
                {
                    SiraliEkle(&bas1, katsayi1[i], derece1[i]);
                }

                int sayac2 = 0;
                int temp2 = N;

                while (temp2 > 0) 
                {
                    int kontrol;
                    do 
                    {
                        kontrol = 1;
                        katsayi2[sayac2] = rand() % 11;
                        derece2[sayac2] = rand() % 7;

                        for (int i = 0; i < sayac2; i++) 
                        {
                            if (katsayi2[sayac2] == temp_katsayi2[i] || derece2[sayac2] == temp_derece2[i]) 
                            {
                                kontrol = 0;
                                break;
                            }
                        }
                    }while (kontrol == 0);

                    temp_katsayi2[sayac2] = katsayi2[sayac2];
                    temp_derece2[sayac2] = derece2[sayac2];
                    sayac2++;
                    temp2--;
                }

                for (int i = 0; i < sayac2; i++) 
                {
                    SiraliEkle(&bas2, katsayi2[i], derece2[i]);
                }
				
                printf("2 adet farkli 0-10 arasi rastgele katsayi ve 0-6 arasi derece ile sayilar olusturuldu ve polinomlara eklendi\n");
                break;
            case 2:
                printf("Polinomlar: \n");
                printf("1. Polinom: ");
                listeyiYazdir(bas1);
                printf("2. Polinom: ");
                listeyiYazdir(bas2);
                break;
            case 3:
                printf("x degerini giriniz: ");
                scanf("%lf", &x);
                printf("1. Polinomun sonucu: %.lf\n", hesapla(bas1, x));
                printf("2. Polinomun sonucu: %.lf\n", hesapla(bas2, x));
                break;
            case 4:
            	printf("Silmek icin derece giriniz--->");
            	scanf("%d",&silinecekDerece);
            	Polinomdan_Eleman_Sil(&bas1, silinecekDerece);
            	Polinomdan_Eleman_Sil(&bas2, silinecekDerece);
            	printf("Yeni Polinom 1: ");
            	listeyiYazdir(bas1);
            	printf("Yeni Polinom 2: ");
            	listeyiYazdir(bas2);
            	break;
            case 5:
            	toplam = PolinomTopla(bas1, bas2);
            	printf("Toplam Polinom: ");
            	listeyiYazdir(toplam);
            	temizle(&toplam);
            	break;
            case 6:
                printf("Cikis yapildi!!!\n");
                temizle(&bas1);
                temizle(&bas2);
                return 0;
            default:
                printf("Hatali Secim!!!\n");
                break;
        }
    }
    return 0;
}
