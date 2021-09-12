/****************************************************************/
/*A sequencia para o sentido depende da conexao das bobinas do motor
/****************************************************************/
#include<16f877.h>
#use delay(clock=4000000)
#use fast_io(A)
#use fast_io(D)
#fuses NOWDT, XT, PUT, NOPROTECT, NOBROWNOUT, NOLVP, NOCPD, NOWRT
/*************************Funcoes***************************************/
//funcao para girar o motor no sentido horario
void horario()
{
  output_d(0b00000110);//escreve 6 na PORTD
  delay_ms(100);
  output_d(0b00000011);//escreve 3 na PORTD
  delay_ms(100);
  output_d(0b00001001);//escreve 9 na PORTD
  delay_ms(100);
  output_d(0b00001100);//escreve 12 na PORTD
  delay_ms(100);
}
//funcao para girar o motor no sentido ant-horario
void anti_hor()
{
  output_d(0b00001100);//escreve 12 na PORTD
  delay_ms(100);
  output_d(0b00001001);//escreve 9 na PORTD
  delay_ms(100);
  output_d(0b00000011);//escreve 3 na PORTD
  delay_ms(100);
  output_d(0b00000110);//escreve 6 na PORTD
  delay_ms(100);
}
/*********************************************************************/
void main()
{
   set_tris_d(0); //PORTD como saida
   set_tris_a(1); //RA1 como entrada
   output_d(0); // zera a POTRD
   while(1)
   {
      if(input(pin_a0)==0)
      {
         anti_hor(); //gira o motor sentido anti-horario
      }
      else
      {
         horario(); //gira o motor sentido horario
      }
   }
}
