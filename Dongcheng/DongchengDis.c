#include "reg_define.h"
unsigned char *word_FCF4;
unsigned short int word_FCE4[4];
unsigned char sub_3092()
{
    unsigned char count_0_3;
    unsigned char count_0_8;
    for(count_0_3 = 0; count_0_3 < 3; count_0_3++){
        word_FCF4 = sub_3260(count_0_3);//3400h,3800h,3C00h
        for(count_0_8 = 0; count_0_8 < 8; count_0_8++){
            *(((unsigned char *)word_FCE4) + count_0_8) = *(word_FCF4 + count_0_8);
        }
loc_30C0:
        if(word_FCE4[0] != 0x5555) continue;
        if(word_FCE4[1] != 0x5555) continue;
        if(word_FCE4[2] != 0xFFFF) continue;
        if(word_FCE4[3] != 0xFFFF) continue;
        return count_0_3;
    }
    return 0xFF;
}


unsigned char *sub_30EA(unsigned char numerIndex)
{
    unsigned char *pStart;
    unsigned char *pEnd;
    unsigned char *pTemp;
    pTemp = sub_3260(numerIndex);
    pStart = pTemp + 0x0008;
    pEnd = pTemp + 0x0400;
    word_FCF4 = pEnd;

    while(1){
        pEnd = pEnd - 0x0004;
        if(pEnd<=pStart) break;
        if(0xff != *(pEnd+0x02)) break;
        word_FCF4 = pEnd;
    }
    return word_FCF4;
}

unsigned short int sub_311F(unsigned char numerIndex, unsigned char searchValue)
{
    unsigned char *pStart;
    unsigned char *pEnd;
    unsigned char *pTemp;

    B = X; // X is an arg
    pTemp = sub_3260(numerIndex);//what this function need as arg
    pStart = pTemp + 0x0008;
    pEnd = pTemp + 0x0400;
    while(1)
    {
        pEnd = pEnd - 0x0004;
        if(pEnd < pStart) break;
        if(0x00 != *(pEnd+0x02)) continue;
        if(searchValue == *pEnd) 
            return pEnd;
    }
    return 0;
}

unsigned char num_2BC6[3]; // max length is 3
unsigned char num_FCE4[4]; // at least 4 member
unsigned char sub_3156(
    unsigned char numberIndex
)
{
    unsigned short int temp_BC;
    unsigned char *ret_sub_3260;
    unsigned char ret_sub_3233;
    ret_sub_3260 = sub_3260(numberIndex);//what this function need as arg
    num_FCE4[0] = 0;
    num_FCE4[1] = 0;
    num_FCE4[2] = 0;
    num_FCE4[3] = 0;
    H = 0x01;
    L = 0x02;

    for(L = 2; L != 0; L --)
    {
        ret_sub_3233 = sub_3233(num_2BC6[numberIndex], 4, ret_sub_3260);
        if(ret_sub_3233 == 0){
            H = 0;
            break;
        }
    }
    for(L = 2; L != 0; L --)
    {
        ret_sub_3233 = sub_3233(num_2BC6[numberIndex], 4, 
            (unsigned char *) (((unsigned char)ret_sub_3260) + 4));
        if(ret_sub_3233 == 0){
            H = 0;
            break;
        }
    }
    if(H == 0)
    {
        return 0xff;
    }
    return 0;
}

unsigned char sub_31AF()
{
    return sub_2A00();
}

unsigned char sub_31B7()
{
    return sub_2A0D();
}
unsigned char sub_31BF()
{
    unsigned short int reg_AX;
    unsigned char reg_A;
    reg_AX = 0xFC80;
    sub_2A1A();
    reg_A = sub_2B32();
    if(reg_A == 0) return 0;
    else return 0xFF;
}

unsigned char sub_31D3(unsigned short int reg_AX)
{
    unsigned short int reg_HL;
    unsigned char reg_B;
    unsigned char reg_A;
    reg_HL = reg_AX;
    do{
        reg_AX = reg_HL;
        reg_B = (unsigned char) (reg_AX >> 8);
        DI();
        reg_A = sub_2A8A();
        EI();
        if(reg_A != 0x1B)
        {
            if(reg_A == 0) return 0;
            if(reg_A == 0x1F) continue;
            else return 0xff;
        }
        reg_AX = reg_HL;
        reg_B = (unsigned char) (reg_AX >> 8);
        DI();
        reg_A = sub_2A2C();
        EI();
    }while(reg_A == 0 || reg_A == 0x1F);
    return 0xFF;
}


unsigned char byte_FCF8;//use in sub_3233, sub_3209
unsigned short int word_FCF6;
unsigned char sub_3209(
    unsigned short int reg_AX,
    unsigned char reg_B, 
    unsigned short int reg_DE)
{
    unsigned short int reg_HL;
    unsigned char reg_A;
    byte_FCF8 = (unsigned char)reg_AX & 0x00ff; 
    word_FCF6 = reg_DE;
    do{
loc_3211:
        reg_B = ((reg_B>>2)&0x3F)+1;
        
        reg_AX = 0xFCF6;
        reg_HL = 0xFCE4;
        DI();
        reg_A = sub_2B3E(reg_B, reg_AX, reg_HL);
        EI();
        if(!(reg_A == 0)){
            return 0;
        }
    }while(reg_A == 0x1F);
loc_3231:
    return reg_A;
}

unsigned char sub_3233(
    unsigned short int reg_AX,
    unsigned char reg_B, 
    unsigned short int reg_DE)
{
    unsigned short int reg_HL;
    unsigned char reg_A;
    byte_FCF8 = (unsigned char)reg_AX & 0x00ff; 
    word_FCF6 = reg_DE;
    do{
loc_323B:
        reg_B = ((reg_B>>2)&0x3F)+1;
        
        reg_AX = 0xFCF6;
        reg_HL = 0xFCE4;
        DI();
        reg_A = sub_2A45(reg_B, reg_AX, reg_HL);
        EI();
        if(!(reg_A == 0)){
loc_325C:
            return 0;
        }
    }while(reg_A == 0x1F);

    return 0xff;
}


unsigned char num_2BC3[]={0x0D, 0x0E, 0x0F};
//return 3400h, 3800h, 3C00h
//[3400]: 55,55,55,55,ff,ff,ff,ff
//[3800]: ff,ff,ff,ff,ff,ff,ff,ff
//[3C00]: ff,ff,ff,ff,ff,ff,ff,ff
unsigned char *sub_3260(unsigned char numerIndex)
{
    unsigned char *temp_value;
    temp_value = ((num_2BC3[numerIndex]<<2) + (num_2BC3[numerIndex]>>7))<<8 + 0;
    return temp_value;
}

unsigned char sub_3279(unsigned char *reg_HL)
{
    if( !(reg_HL[0] != 0x00) && 
        !(reg_HL[1] != 0x00) &&
        !(reg_HL[2] != 0x00) &&
        !(reg_HL[3] != 0x00) &&
        !(reg_HL[4] != 0x00) &&
        !(reg_HL[5] != 0x00) &&
        !(reg_HL[6] != 0x00) &&
        !(reg_HL[7] != 0x00) )
    {
        return 0;
    }
loc_32AA:
loc_32B0:
    return 0xff;
}


unsigned char sub_32B2(unsigned char *reg_HL)
{

    if( !(reg_HL[0] != 'U') && 
        !(reg_HL[1] != 'U') &&
        !(reg_HL[2] != 'U') &&
        !(reg_HL[3] != 'U') &&
        !(reg_HL[4] != 0xff) &&
        !(reg_HL[5] != 0xff) &&
        !(reg_HL[6] != 0xff) &&
        !(reg_HL[7] != 0xff) )
    {
        return 0;
    }
loc_32E7:
loc_32E9:
    return 0xff;
}


unsigned char sub_32EB(unsigned char *reg_HL)
{
    if( !(reg_HL[0] != 0xff) && 
        !(reg_HL[1] != 0xff) &&
        !(reg_HL[2] != 0xff) &&
        !(reg_HL[3] != 0xff) &&
        !(reg_HL[4] != 0xff) &&
        !(reg_HL[5] != 0xff) &&
        !(reg_HL[6] != 0xff) &&
        !(reg_HL[7] != 0xff) )
    {
        return 0;
    }
loc_3320:
    return 0xff;
}

unsigned char sub_3325()
{
    unsigned char reg_A;
    reg_A = 0x01;
    if(!(reg_A < 0x01))
    {
        if(!(reg_A >= 0xff))
        {
            reg_A = 0x02;
            if(!(reg_A >= 0xfe))
            {
                reg_A = 0x01;
                if(!(reg_A >= 0xFE))
                {
                    reg_A = 0x01;
                    if(!(reg_A >= 0xff))
                    {
                        reg_A = 0x00;
                        return reg_A;
                    }
                }
            }
        }
    }

loc_3345:
    reg_A = 0xff;
loc_3347:
    return reg_A;
}