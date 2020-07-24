#include <stdio.h>
#include <string.h>
#include <math.h>

typedef enum {
    CONSTANT_E = 0, // С��һ��ĳ���
    TEN_THOUSAND_E = 1,     //��
    HUNDRED_MILLION_E = 2,  //��
    OMEN_E = 3              //��
}ORDER_OF_MAGNITUDE_E;

ORDER_OF_MAGNITUDE_E judge_magnitude(unsigned long long int num)
{
    unsigned long long int magnitude = 10000;// ����
    unsigned long long int merchant = num; //��
    unsigned int flag = 0;
    do {
        merchant = merchant / magnitude;
        flag++;
    } while (merchant);
    return --flag;
}
void deal_ten_thousand(ORDER_OF_MAGNITUDE_E e_magnitude, int decimals_flag, unsigned int num)
{
    unsigned int redminer = 0;// ����
    unsigned int divisor = 1000; //������
    unsigned int merchant = num; //��
    unsigned int flag = 0, true_flag = 0;
    do {
        redminer = merchant % divisor;
        merchant = merchant / divisor;
        switch (merchant) {
        case 0:
            if (!flag && true_flag && !decimals_flag) {
               printf_s("��");
                flag = 1;
            }
            break;
        case 1:
            if (10 != divisor)
               printf_s("Ҽ");
            else {
                if (decimals_flag)
                   printf_s("Ҽ");
            }
            true_flag = 1;
            break;
        case 2:
           printf_s("��");
            true_flag = 1;
            break;
        case 3:
           printf_s("��");
            true_flag = 1;
            break;
        case 4:
           printf_s("��");
            true_flag = 1;
            break;
        case 5:
           printf_s("��");
            true_flag = 1;
            break;
        case 6:
           printf_s("½");
            true_flag = 1;
            break;
        case 7:
           printf_s("��");
            true_flag = 1;
            break;
        case 8:
           printf_s("��");
            true_flag = 1;
            break;
        case 9:
           printf_s("��");
            true_flag = 1;
            break;
        }
        if (1000 == divisor && 0 != merchant) {
           printf_s("Ǫ");
        }
        else if (100 == divisor && 0 != merchant) {
           printf_s("��");
        }
        else if (10 == divisor && 0 != merchant) {
            if (decimals_flag) {
               printf_s("��");
            }
            else {
               printf_s("ʰ");
            }
        }
        else if (1 == divisor && 0 != merchant) {
            if (decimals_flag) {
               printf_s("��");
            }
        }
        divisor = divisor / 10;
    } while (redminer && (merchant = redminer));
    if (e_magnitude == CONSTANT_E) {
        if (!decimals_flag) {
           printf_s("Ԫ");
        }
    }
    else if (e_magnitude == TEN_THOUSAND_E) {
       printf_s("��");
    }
    else if (e_magnitude == HUNDRED_MILLION_E) {
       printf_s("��");
    }
    else if (e_magnitude == HUNDRED_MILLION_E) {
       printf_s("��");
    }
}


void tran(double num)
{
    char buff[1024] = { 0 };
    unsigned long long int n = (unsigned long long int)num;
    unsigned int little_ten_thousan = 0;
    ORDER_OF_MAGNITUDE_E e_magnitude = 0;
    unsigned int redminer = 0;// ����
    unsigned int merchant = n; //��
    unsigned int result = 0;
    unsigned int decimals = 0;
    double tmp = 0.0;
    do {
        if (merchant == 0) break;
        e_magnitude = judge_magnitude(merchant);
        if (e_magnitude == TEN_THOUSAND_E) {
            redminer = merchant % 10000;
            result = merchant / 10000;
            merchant = redminer;
        }
        else if (e_magnitude == HUNDRED_MILLION_E) {
            redminer = merchant % 100000000;
            result = merchant / 100000000;
            merchant = redminer;
        }
        else if (e_magnitude == HUNDRED_MILLION_E) {
            redminer = merchant % 1000000000000;
            result = merchant / 1000000000000;
            merchant = redminer;
        }
        else {
            redminer = merchant % 1;
            result = merchant / 1;
            merchant = redminer;
        }
        deal_ten_thousand(e_magnitude, 0, result);
    } while (merchant);
    decimals = (unsigned int)((num - (double)n + 0.001) * 100);//���־��о�������
    deal_ten_thousand(CONSTANT_E, 1, decimals);
}

int main(int argc, char* argv[])
{
    double num;
    while (scanf_s("%lf", &num) != EOF)
    {
       printf_s("�����");
        tran(num);
       printf_s("\n");
    }
    return 0;
}