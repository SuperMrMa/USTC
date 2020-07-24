#include <stdio.h>
#include <string.h>
#include <math.h>

typedef enum {
    CONSTANT_E = 0, // 小于一万的常数
    TEN_THOUSAND_E = 1,     //万
    HUNDRED_MILLION_E = 2,  //亿
    OMEN_E = 3              //兆
}ORDER_OF_MAGNITUDE_E;

ORDER_OF_MAGNITUDE_E judge_magnitude(unsigned long long int num)
{
    unsigned long long int magnitude = 10000;// 量级
    unsigned long long int merchant = num; //商
    unsigned int flag = 0;
    do {
        merchant = merchant / magnitude;
        flag++;
    } while (merchant);
    return --flag;
}
void deal_ten_thousand(ORDER_OF_MAGNITUDE_E e_magnitude, int decimals_flag, unsigned int num)
{
    unsigned int redminer = 0;// 余数
    unsigned int divisor = 1000; //被除数
    unsigned int merchant = num; //商
    unsigned int flag = 0, true_flag = 0;
    do {
        redminer = merchant % divisor;
        merchant = merchant / divisor;
        switch (merchant) {
        case 0:
            if (!flag && true_flag && !decimals_flag) {
               printf_s("零");
                flag = 1;
            }
            break;
        case 1:
            if (10 != divisor)
               printf_s("壹");
            else {
                if (decimals_flag)
                   printf_s("壹");
            }
            true_flag = 1;
            break;
        case 2:
           printf_s("贰");
            true_flag = 1;
            break;
        case 3:
           printf_s("叁");
            true_flag = 1;
            break;
        case 4:
           printf_s("肆");
            true_flag = 1;
            break;
        case 5:
           printf_s("伍");
            true_flag = 1;
            break;
        case 6:
           printf_s("陆");
            true_flag = 1;
            break;
        case 7:
           printf_s("柒");
            true_flag = 1;
            break;
        case 8:
           printf_s("捌");
            true_flag = 1;
            break;
        case 9:
           printf_s("玖");
            true_flag = 1;
            break;
        }
        if (1000 == divisor && 0 != merchant) {
           printf_s("仟");
        }
        else if (100 == divisor && 0 != merchant) {
           printf_s("佰");
        }
        else if (10 == divisor && 0 != merchant) {
            if (decimals_flag) {
               printf_s("角");
            }
            else {
               printf_s("拾");
            }
        }
        else if (1 == divisor && 0 != merchant) {
            if (decimals_flag) {
               printf_s("分");
            }
        }
        divisor = divisor / 10;
    } while (redminer && (merchant = redminer));
    if (e_magnitude == CONSTANT_E) {
        if (!decimals_flag) {
           printf_s("元");
        }
    }
    else if (e_magnitude == TEN_THOUSAND_E) {
       printf_s("万");
    }
    else if (e_magnitude == HUNDRED_MILLION_E) {
       printf_s("亿");
    }
    else if (e_magnitude == HUNDRED_MILLION_E) {
       printf_s("兆");
    }
}


void tran(double num)
{
    char buff[1024] = { 0 };
    unsigned long long int n = (unsigned long long int)num;
    unsigned int little_ten_thousan = 0;
    ORDER_OF_MAGNITUDE_E e_magnitude = 0;
    unsigned int redminer = 0;// 余数
    unsigned int merchant = n; //商
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
    decimals = (unsigned int)((num - (double)n + 0.001) * 100);//发现具有精度问题
    deal_ten_thousand(CONSTANT_E, 1, decimals);
}

int main(int argc, char* argv[])
{
    double num;
    while (scanf_s("%lf", &num) != EOF)
    {
       printf_s("人民币");
        tran(num);
       printf_s("\n");
    }
    return 0;
}