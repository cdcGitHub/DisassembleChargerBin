

WTIMK  bit2  第三位
HL 在函数调用前会给定
union REG_AX
{
    unsigned short int _World;
    struct  {
        unsigned char A:8;
        unsigned char X:8;
    }_byte;
}reg_AX;

union REG_BC
{
    unsigned short int _World;
    struct  {
        unsigned char B:8;
        unsigned char C:8;
    }_byte;
}reg_BC;

union REG_DE
{
    unsigned short int _World;
    struct  {
        unsigned char D:8;
        unsigned char E:8;
    }_byte;
}reg_DE;

union REG_HL
{
    unsigned short int _World;
    struct  {
        unsigned char H:8;
        unsigned char L:8;
    }_byte;
}reg_HL;

#define AX reg_AX._World
#define A  reg_AX._byte.A
#define X  reg_AX._byte.X

#define BC reg_BC._World
#define B  reg_BC._byte.B
#define C  reg_BC._byte.C

#define DE reg_DE._World
#define D  reg_DE._byte.D
#define E  reg_DE._byte.E

#define HL reg_HL._World
#define H  reg_HL._byte.H
#define L  reg_HL._byte.L

void fun_2076(void)
{
   PRM00 = 0x01;
}


void fun_207A(void)
{
   TCL50 = 0x05;
   MK0H.TMMK01 = 0；
   Var_FF17 = 0xF3;
}


void fun_2084(void)
{
   fun_208F();
   while( !(IF0H & 0x20)  );
   fun_2093();
}

void fun_208F(void)
{
	TMC00 = 0x0C;
}

//请中断标志
void fun_2093(void)
{
	TMC00 = 0x00;
	IF0H &= ~0x20;
}


void fun_209A(void)
{
	TMC50 |= 0x80;      //需确认07 代表第几位
}

unsigned short int Var_FE70;

unsigned short int Var_FE73;    // Sum
void fun_2160(void)
{
	int ADC_data, ADC_data_sum;
	IF1L &= ~0x01;      			// ADIF 清零
	ADM |= 0x80;       				//需确认07 代表第几位
	
	while( !(IF1L & 0x01) );
	Var_FE70 = ADCR; 
	
	
	ADM &= ~0x80;
	
	Var_FE73 += Var_FE70;    		//累加
	
	
}



void fun_2186(char temp_D, char temp_E, char temp_B)
{
	TMHMD1 = 0x40;
	CMP01  = 0x27;
	IF0H   &= ~0x04;
	MK0H   &= ~0x04;
	
	TMHMD1 = 0xC0;
	EI();
	byte_FE62 &= ~0x08;
	P3 = Var_FE62;
	PM3 &= ~0x08;    //PM33   当 P17/TO50/TI50 和 P33/TO51/TI51/INTP4 引脚用于定时器输出时，将 PM17 和 PM33 以及 P17 与 P33 的输出 锁存器清零
	TMC51 = 0x07;
	TCL51 = 0x04;
	CR51 = 0x63;
	TMC51 = 0x87;
	
	do 
	{
		byte_FEC8 = 0;
		if( !(temp_B & 0x01) )
	    {
			byte_FEC9 = temp_E;
	    }
		else 
		{
			byte_FEC9 = temp_D;
		}
		//loc_21BB
		do
		{
			if( !(MK0H & 0x04) )
			{
			   WDTE = 0xAC;
			}
	 ///loc_21C2
			if( !(byte_FEA0 & 0x02) )
			{
			  if( byte_FEB7 ==  0 )
			  {
				//loc_21E1:
				goto loc_21E1;
			  }
			}
			else
			{
				if( byte_FEC8 > byte_FEC9 )
					break;
			}
		
		}while( 1);
		temp_B--;
		if( temp_B == 0 ) 
			goto loc_21E1;
		if( temp_B & 0x01 )
		{
			TMC51 = 0x87;
		}
		else
		{
			TMC51 = 0x7;
		}
	}while(1);
loc_21E1:	
	DI();
	TMC51 = 0x07;
	TMHMD1 = 0x40;
	MK0H |= 0x40;
}
	
	
//OK	
unsigned char num_FE20[32] ={0};

void fun_2600(void)
{
	unsigned char *p = num_FE20;
	if( byte_FEC0 == 10 )
	{
		byte_FD40 = 0;
	}
	//B loc_260B:
	else
	{
		if( byte_FD43 & 0x01 )
		{
			sub_2948();
			sub_27A1();
			sub_27EF();
			DI();
			sub_27A8();
			sub_283D();
			DI();
			sub_27A1();
			sub_28D7();
			DI();
			sub_27A8();
			if(  byte_FD57 & 0x08  )
			{
				return;
			}
			else
			{
				if( !( byte_FD43 & 0x04 ) )
				{
					return;
				}
				else
				{
					byte_FE91 &= ~0x01;
					while(1)
					{
						if( byte_FEB6 != 0 )
						{
							byte_FD57 = ( byte_FD57 | 0x01 );
							return;
						}
						//else
						{
							for( i=0; i <= 32; i++ )
							{
								num_FE20[i] = 5;
							}
							
							sub_7F3();
							if( !( byte_FE90 & 0x02) )
							{
								sub_8E5();
								if( !(byte_FE90 & 0x08) )
								{
									byte_FE91 &= ~0x01;
									byte_FE3E &= 0xF0;
									sub_95D();
									if( byte_FE90 & 0x10 )
									{
										byte_FE92 |= 0x02;
										
										for( i= 22; i<= 32; i++ )
										{
											num_FE20[i] = 0;
										}
										num_FE20[24] = 0x20;
										num_FE20[25] = 0x20;
										num_FE20[31] = 0x04;
										
									}
									//loc_268F
									else{
										byte_FE92 &= ~0x02;
									}
									//loc_2691
									if( byte_FEC0 != 0x0A )
									{
										sub_80D();
									}
									//loc_2699
									if( byte_FE31 <= 0x10 )
									{
										byte_FD57 = ( byte_FD57 | 0x02 );
										return;
									}
									//loc_26D0
									else
									{
										break;
									}
									
								}
								//loc_26A7
								else
								{
									if( ( ( byte_FE34 & 0x0F) == 0x01 ) && ( byte_FE35 == 0x11 ) )
									{
										byte_FD57 |= 0x04;
										return;
									}
									//loc_26BE
									
								}
							}
							//loc_26BE
							else
							{
								if( byte_FE91 & 0x01 )
								{
									byte_FD57 |= 0x02;
									return;
								}
								//loc_26CB
								else
								{
								  byte_FE91 |= 0x01;
								}
							}
						}
					}
					
					//loc_26D0
					if( word_FE32 != 0 )
					{
						byte_FE92 |= 0x04;
						return;
					}
					else
					{
						byte_FE92 &= ~0x04;
						return;
					}
				}
			}
		}
		else
		{
			if( byte_FD40 != 6 )
			{
				sub_26ED();
			}
		}
	}
}

 

unsigned char num_2480[7] = {0x40,0x1E,0x00,0x1E,0x00,0x1F,0x1F};
unsigned char num_2400[] = {0x04,0x00,
							0x05,0x76,
							0x05,0x70,
							0x05,0x69,
							0x05,0x63,
							0x05,0x5E,
							0x05,0x58,
							0x05,0x53,
							0x05,0x4F,
							0x05,0x4A,
							0x05,0x46,
							0x05,0x42,
							0x04,0xFC,
							0x04,0xEE,
							0x04,0xE0,
							0x04,0xD4,
							0x04,0xC8,
							0x04,0xBD,
							0x04,0xB2,
							0x04,0xA8,
							0x04,0x9E,
							0x04,0x95,
							0x04,0x8D,
							0x04,0x85,
							0x04,0x7E,
							0x04,0x76,
							0x04,0x70,
							0x04,0x69,
							0x04,0x63,
							0x04,0x5E,
							0x04,0x58,
							0x04,0x00};
//    地址：FD00
void sub_26ED(void)
{
	unsigned char temp_D,temp_E;
	unsigned char * temp_DE;
    
	TMHMD1 = 0x40;
	if( byte_FD40 == 4 )
	{
		temp_D = 0xFD;
	    temp_E = 0x00;
	}
	//loc_26FC
	else
	{
		if( byte_FD40 == 6 )
		{
			temp_D = 0x24;    //数组
			temp_E = 0x80;
		}
		//loc_2706
		else
		{
			temp_D = byte_FD40 + 0x20;
			temp_E = 0x00;
			//temp_D = (unsigned char *)( temp_D << 8) )
		}
	}
	//loc_270B
	temp_DE = (unsinged char *) ((temp_D <<8) + temp_E);
	if( *temp_DE != 0 )
	{
		// loc_2713
		CMP01 = *temp_DE;      //需确认
		IF0H &= ~0x04;          //WTIIF  中断请求标志位
		MK0H &= ~0x04;          //WTIMK  中断屏蔽标志位
		TMHMD1 = 0xC0;          // 定时器
		EI();
		byte_FE62 &= ~0x08;    
		P3 = byte_FE62;        //晶振相关
		PM3 &= ~0x08;           // 输出
		temp_DE++;        //这里是地址加一
		
		do
		{
			byte_FEC8 = 0;
			if( ( (*(temp_DE)) & 0x20 )) 
			{
				if( ( (*(temp_DE)) & 0x40 ) )
				{
					byte_FEC9 = 0x10;
				}
				else  //loc_2744
				{
					byte_FEC9 = 0x04;
				}
			}
			else  //loc_273B
			{
				if( ( (*(temp_DE)) & 0x40 ) )
				{
					byte_FEC9 = 0x08;
				}
				else   //loc_274A
				{
					byte_FEC9 = 0x02;
				}
			}
			//loc_274E
			if( !((*(temp_DE)) & 0x80) )
			{
				//loc_2754
				if( ( (*(temp_DE)) & 0x1F ) == 0x1F ) //{0x40,0x1E,0x00,0x1E,0x00,0x1F,0x1F};
				{
					if( (byte_FD43 & 0x01) )
					{
						goto loc_2795;
					}
					temp_DE++;   // 数组序号
					if( ( (*(temp_DE)) & 0x1F ) == 0x1F )
					{
						goto loc_2795;
					}
					else
						continue;
				}
				else  //loc_276A
				{
					TMC51 = 0x07;      //定时器
					if( (*(temp_DE))  != 0 )
					{
						TCL51 = *((unsigned char *)((0x24 <<8) + ((*(temp_DE)<< 1))) );   //时钟选择
						WTM = *((unsigned char *)((0x24 <<8) + ((*(temp_DE)<< 1))) + 1);
						TMC51 = 0x87;
					}
					
				}
			}
			//loc_277F
			do
			{
				if( !(MK0H & 0x04) )
				{
					WDTE = 0xAC;   //清看门狗
				}
				//loc_2786
				if( byte_FEB7 )
				{
					goto loc_2795;
				}
			}while(byte_FEC8 < byte_FEC9);	  //  byte_FEC8 计数器 
			temp_DE++;
		}while((temp_DE- (unsinged char *) ((temp_D <<8) + temp_E)) < 256);
		
	}
	//loc_2795
	loc_2795:
	 TMC51 = 0x07;         
	 TMHMD1 = 0x40;
	 MK0H |= 0x04;
	 DI();
}



// ok
void sub_27A8(void)
{
	byte_FE82 &= ~0x04;
	CR01 = byte_FE82;
}

//OK
void sub_27AF(void)
{
	DI();
	byte_FD44 = MK0L;
	byte_FD45 = MK0H;
	byte_FD46 = MK1L;
	byte_FD47 = MK1H;
	MK0L = 0xFF;
	MK0H = 0xFF;
	MK1L = 0xFF;
	MK1H = 0xFF;
}
//ok
void sub_27D0(void)
{
	IF0L = 0x00;
	IF0H = 0;
	IF1L = 0;
	IF1H = 0;
	
	MK0L = byte_FD44;
	MK0H = byte_FD45;
	MK1L = byte_FD46;
	MK1H = byte_FD47;
}

//OK
void sub_27EF()
{
    unsigned char return_2BC9;
	unsigned char return_2CE8;
	sub_27AF();
	return_2BC9 = sub_2BC9();    //sub_2BC9 是有返回值
	if( return_2BC9 == 0 || ( return_2BC9 == 0x01 ) )
	{
		//loc_27FE
		return_2CE8 = sub_2CE8(byte_FD50,1);
		if( return_2CE8 == 0 )
		{
			if( (byte_FD43 & 0x02) ||  (byte_FD50 != 0x04) )
			{
				//loc_2827
				byte_FD40 = byte_FD50;
			}
			else 
				byte_FD40 = 0x01;
			
		}
	}
	//loc_280C
	else
	{
       byte_FD40 = 0x06;
	   byte_FD50 = 0x06;
	}
	//loc_282D
	if( byte_FD40 >= 0x07 )
	{
		byte_FD40 = 0x06;
	}
	sub_27D0();
	
}

//OK
//OK
//注意：byte_FD41 byte_FD42  是一个16位
unsigned short int byte_FD41;
void sub_283D(void)
{
	byte_FD43 &= ~0x04;
	
	do 
	{
		sub_26ED();
		byte_FD41 = 0;
		
		do 
		{
			WDTE = 0xAC;
			sub_EDF();
			if( byte_FEB7 == 0 )
			{
				break;
			}
			byte_FD41 += 0x01;
			if((byte_FD41 & 0xff00) == 0x0600  ) return;
		}while(1);
		
	//loc_2871	
		byte_FD41 = 0;
		byte_FD43 |= 0x04;
		
		do
		{
			WDTE = 0xAC;
			sub_EDF();
			if( byte_FEB7 == 0x0F )
			{
				byte_FD40++；
				if( byte_FD40 >= 0x07 )
				{
					byte_FD40 = 0;
					break;
				}
				else  //loc_289E
				{
					if( byte_FD43 & 0x02 ) 
						break;
					else
					{
						if( byte_FD40 == 4 )
							byte_FD40 = 5;
						break;
					}
				}
			}
			else  //loc_28B4
			{
				byte_FD41 += 1;
				if( (byte_FD41 & 0xff00) == 0x0600 )
				{
					byte_FD40 = byte_FD50;
					byte_FD57 |= 0x08;
					return;
				}
			}
		}while(1);
		
	}while(1);
	
}


//OK
void sub_28D7(void)
{
	unsigned char return_2BC9;
	unsigned char return_2D3B;
	unsigned char return_2E0A;
	unsigned char return_2CE8;
	if( byte_FD40  == byte_FD50 )
	{
		return;
	}
	sub_27AF();
	return_2BC9 = sub_2BC9();
	if( (return_2BC9 == 0) || (return_2BC9 == 1) )
	{
		//loc_28EF
		byte_FD56 = 0;
		byte_FD50 = byte_FD40;
		
		do 
		{
			return_2D3B = sub_2D3B( byte_FD50,1 );
			if( return_2D3B )
			{
				if( return_2D3B == 0xF5 )
				{
					return_2E0A = sub_2E0A();
					if( return_2E0A )
					{
						if( return_2E0A != 1 ) break;
					}
					//else // loc_2918
					{
						byte_FD56 = 1;
					}
				}
				else  //loc_2944
				{
					break;
				}
			}
			else  //loc_291F
			{
				byte_FD50 = 0;
				return_2CE8 = sub_2CE8(byte_FD50,1 );
				if( return_2CE8 ) break;
				if( byte_FD50 != byte_FD40 )
				{
					break;
				}
				if( byte_FD56 == 0 ) break;
				
				sub_2FC8();
			}
		}while(1);
	}
	sub_27D0();
}


void sub_2948()
{
	byte_FD43 &= ~0x02;
	sub_80D();
	if( !(byte_FE90 & 0x01) )
	{
		byte_FEB4 = 0x20;
		
	}
	//loc_2963
	word_FED0 = 0;
	
	do{
		PM3 &= ~0x01;
		
		
		PM3 |= 0x01;
		
		do
		{
			if( P3 & 0x01 )
			{
				//loc_297C
				if( 
			}
		}while(1);
	}while(1);
}


//OK
void sub_2A00(void)
{
	byte_FFC0 = 0xA5;
	byte_FFC4 = 1;
	byte_FFC4 = 0xFE; 
	byte_FFC4 = 1;
}
//OK
void sub_2A0D(void)
{
	byte_FFC0 = 0xA5;
	byte_FFC4 = 0;
	byte_FFC4 = 0xFF; 
	byte_FFC4 = 0;
}

//OK
unsigned char sub_2A2C(void)
{
	if(!sub_2B6A())
	{
		return 5;
	}
	else
	{
		
	}
	
}

//need check
void sub_2A45(void)
{
	if( !sub_2B89() )
	{
		return 5;
	}
	else
	{
	}
}


void sub_2A8A()
{
	if( !sub_2B6A() )
	{
		return 5;
	}
	else
	{
	}
}

//Nop
void sub_2B32()
{
}

void sub_2B3E()
{
}

bool sub_2B6A(char temp)
{
	if( (temp > 0x20) || (temp < 0x30) )	
	{
		if( temp >= 0xFF )
		{
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if( temp < 0x06 )
		{
			temp << 4;
		}
		
	}
}

void sub_2B89()
{
}

void sub_2BC9()
{
}



void sub_2CE8()
{
}



void sub_2D3B()
{
	
}


void sub_2E0A()
{
	
}

unsigned char num_2BC3[3] = {0x0D,0x0E,0x0F};
unsigned char num_2BC6[3] = {0x00,0x00,0x00};
unsigned char sub_2FC8()
{
	unsigned char return_temp,tempB;
	unsigned char return_C;
	return_temp = sub_3325();
	if( return_temp )
	{
		return_C = 0xF4;
	}
	//loc_2FD6
	else
	{
		return_temp = sub_3092();
		if( return_temp == 0xFF )
		{
			return_C = 0xFA;
		}
			
		else
		{
			word_FCE8 = return_temp;
			tempB = return_temp;
			do
			{
				tempB--;
				if( word_FCE8 == tempB )
				{
					return_C = 0xF9;
					return return_C;
				}
				sub_3260();
				return_temp = sub_3279();
				if( return_temp == 0 )
				{
					break;
				}
				
				
			}while(1);
			
			byte_FCE9 = tempB;
			sub_31AF();
			return_temp = sub_31BF();
			if( return_temp )
			{
				return_C = 0xFE;
				return return_C;
			}
			byte_FCF2 = 0x02;
			
			//loc_3012
			do
			{
				return_C = byte_FCE9;
				return_temp = sub_31D3(num_2BC6[return_C-1],num_2BC3[return_C-1]);
				if( return_temp == 0 )
				{
					return_C = 0;
					sub_31B7();
					return return_C;
				}
				byte_FCF2--;
				if( byte_FCF2 == 0 )
				{
					break;
				}
			}while(1);
			
			return_temp = sub_3156(byte_FCE9);
			if( return_temp == 0 )
			{
				return_C = 0xFC;
			}
			sub_31B7();
			return return_C;
			
		}
		
	}
}






