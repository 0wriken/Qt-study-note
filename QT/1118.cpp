u16 data_recieve()
{
	u8 data;
	CS=0;
	BUSY=0;
	for(int i=0;i<8;i++)
	{
		DLCK=0;
		if(DIN)
		data|=DIN&(0x80>>i;
	else
		data&=~(DIN&(0x80>>i));
		DLCK=1;

	}
	BUSY=1;
	return data;

}
U16 send_com(u8 data)
{
	U16 buf=0;
	CS=0; 
	for(int i=0;i<8;i++)
	{
		DLCK=0;
		if(data&(0x80>>i))
			DIN=1;//??
		else 
			DIN=0;
		delay_us(1);
		DLCK=1;
		delay_us(1);//??
	}
	BUSY=1;
	DLCK=0;
	delay_us(1);
	DLCK=1;
	delay_us(1);//??
	for(int j=0;j<16;j++)
	{
		DLCK=0;
	delay_us(1);
		DLCK=1;
	delay_us(1);
		buf<<1;
		buf|=DOUT;
		elay_ms(1);
	}

	return buf>>=4;
}
static u32 sx[]={0};
static u32 sy[]={0};
static j=0;
static k=0;
static u32 rsx[]={0};
static u32 rsy[]={0};
void save(u8* x,u8 *y)
{

	if(j==0)
	{
		sx[j++]=x;
		sy[j++]=y;	
	}
	if(abs(sx[j-1])-x)>20||abs(sy[j-1]-y>20)
	return ;
	else
	{ 
		sx[j++]=x;
		sy[j++]=y;
		printf("x:%d\n,y:%d\n",x,y);
		rsx[k++]=(sx[j-1]+sx[j-2])/2;
		rsy[k++]=(sy[j-1]+sy[j-2])/2;
		sx[j-1]=rsx[k-1];
		sy[j-1]=rsx[k-1];
	}
}
void play_xy(u8 *x,u8 *y)
{
		*x=send_com(0xd0);
		*y=send_com(0x90);
		save(x,y);
} 
u8 temp=1;//标志位
u8 i=0;
void init_timer7()
{
	RCC->APB2ENR|=(0X1<<5);
	TIM7->PSC = 8400 - 1;			//进行8400分频，计数器时钟为10KHz 84 1m 1us 100084
	TIM7->CNT = 0;					//清空计数器的值
	TIM7->ARR = 0;					//延时为1ms
	TIM7->EGR |= 0X1 << 0;			//设置一次UG位
	TIM7->SR &= ~(0X1 << 0);		//清除一次更新标志位(防止出错)
	TIM7->DIER|=(0X1<<0);
	TIM7->CR1 = 0;					//清空控制寄存器1的值
	TIM7->CR1 |= 0X0 << 3;			//定时完成以后自动停止计数
	TIM7->CR1 |= 0X1 << 0;			//开启计数器
	NVIC_SetPriorityGrouping(7-2);//抢占位
	inter6=NVIC_EncodePriority(7-2,0, 0);//抢占与响应优先级
	NVIC_SetPriority(TIM7_IRQn, inter6);//中断类型
	NVIC_EnableIRQ(TIM7_IRQn);	

}

void TIM7_IRQHandler (void)
{
	static u8 temp=0xff;//标志位
	static u8 i=0;
	u16 x=0;
	u16 y=0;
	if(TIM7->SR&(0X1<<0))
	{
		TIM7->SR&=~(0X1<<0);
		if(T_PEN==0)
			temp&=~((0x80>>(i%8));
		else 
			temp|=(0x80>>(i%8);
		i++;
		if(temp==0)
		{
			play_xy(&x,&y);
		}


}



