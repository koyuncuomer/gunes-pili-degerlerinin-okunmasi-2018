#include <16F877A.h>
#fuses XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NOWRT, NODEBUG, NOCPD
#define LCD_DATA4    PIN_B3
#define LCD_DATA5    PIN_B2
#define LCD_DATA6    PIN_B1
#define LCD_DATA7    PIN_B0
#define LCD_RW_PIN      PIN_D2
#define LCD_ENABLE_PIN   PIN_B5
#define LCD_RS_PIN       PIN_B4
#device adc = 10
#use delay(clock=4000000)
#include <lcd.c>
void main(){
	float okunandeger;
	float volt;
	float akim;
	set_tris_a(0xFF); //A portunu giriş olarak tanımlıyoruz
	set_tris_b(0x00); //B portunu çıkış olarak tanımlıyoruz
	lcd_init(); //LCD başlatma
	delay_ms(5);
	setup_adc_ports(AN0);
	setup_adc(ADC_CLOCK_DIV_64); 
	set_adc_channel(0);//adc verileri okuyacağı kanal
	setup_vref(FALSE);
	while(true){
		delay_ms(10);
		set_adc_channel(0);
		read_adc(ADC_START_ONLY);//veri okuma başlıyor
		delay_ms(2);
		okunandeger = read_adc();
		volt = okunandeger * 10.0;
		volt = volt / 1023.0 ;
		delay_ms(10);
		akim = volt / 20000.0;
		lcd_gotoxy(1,1);
		printf(lcd_putc,"Volt:%2.5f"volt);                           
		delay_ms(100);                                         
		printf(lcd_putc,"V");
		delay_ms(100);
		lcd_gotoxy(1,2);
		printf(lcd_putc, "Akim:%2.6f"akim);
		delay_ms(100);
		printf(lcd_putc, "A");
		delay_ms(100);
	}
}
