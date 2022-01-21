# Environment Meter Dragon

### Sobre
   1.1 Medidor climático realizado durante a disciplina de Computação Física e Aplicações da graduação de Sistemas de Informação sob orientação do professor Fábio Nakano. Realizado com a colaboração de Laura Steinert de Freitas e Lais Garcia.
   
   1.1. Como?
      
      Usando ESP32 e medidores climáticos, juntamente com o Firebase.
 
 ### Aparência
 
 ##
 
 ![Dragão de plástico branco](https://cdn.discordapp.com/attachments/897837705172516884/910499807095820308/IMG_20211117_085139398.jpg)
  
  ### 1.2 Infraestrutura
  
  ## 
  
  #### 1.2.1 Visão geral
  
  ##### 1.2.2 Dispositivo - Dragão Meteorológico
  
  &emsp; 1.2.2.1 Lista de peças
         
  &emsp;  &emsp;  &emsp;Sensor BME280, ESP32, Jumpers.
  
  &emsp;  &emsp;  &emsp;Para o dragão: Filamento PLA Transparente, Impressora 3D Ender-3 Pro - Creality.
               
  &emsp;  &emsp; 1.2.2.2 Circuito (lista de conexões)
  
  &emsp;  &emsp; &emsp;1.2.2.3 Montagem
  
  <img src = "images/WhatsApp Image 2022-01-07 at 00.06.24 (1).jpeg">
  &emsp;  &emsp; &emsp;
  
  <img src = "images/WhatsApp Image 2022-01-07 at 00.06.24.jpeg">
  
   &emsp;  &emsp; 1.2.2.4 Programação do dispositivo
   
   &emsp;  &emsp;  &emsp; Uso das bibliotecas <Adafruit_NeoPixel.h> para a manipulação dos LEDs e <Adafruit_BME280.h> e <Adafruit_Sensor.h> para a manipulação do BME280.
   
   ##### 1.2.3 Construção física
   
   &emsp;  &emsp;1.2.3.1 Visão geral
   
   &emsp; &emsp;  &emsp; 1.2.3.2 Dragão (impressão 3D)
   
   &emsp;  &emsp; &emsp;  &emsp; Foi utilizado o Filamento PLA Transparente de 1.75mm, juntamente com a Impressora 3D Ender-3 Pro - Creality, levando cerca de 56h de impressão, com alguns defeitos pontuais.
   
   &emsp;  &emsp; &emsp;  &emsp; Projeto: ThingVerse, thing 1624412 - **https://www.thingiverse.com/thing:1624412**

   ##### 1.2.4  Visualização (aplicativos)
   
   &emsp;  &emsp; 1.2.5.1 Visão geral, proposta geral
   
   &emsp;  &emsp;&emsp; 1.2.5.2 Aplicativo
   
   
    -------TODO
            1.2.5.2.1 Apresentar compilado, para baixar, instalar e usar
                   1.2.5.2.1.1 Instruções para instalar
                   1.2.5.2.1.2 Instruções para usar
               1.2.5.2.2 Construção
                   1.2.5.2.2.1 Ferramentas de desenvolvimento utilizadas
                   1.2.5.2.2.2 Código-fonte
                   1.2.5.2.2.3 Instruções para compilação
           1.2.5.3 Página web
               1.2.5.3.1 Link para experimentar visualização
                   Captura de tela (para o caso do link quebrar - talvez aconteça daqui uns anos...)
               1.2.5.3.2 Construção
                   1.2.5.2.2.1 Ferramentas de desenvolvimento utilizadas
                   1.2.5.2.2.2 Código-fonte
                   1.2.5.2.2.3 Instruções para publicização
       1.2.6 Integração das partes, apresentação do conjunto funcionando
       1.3 Resultados - do ponto de vista da aplicação (por exemplo, gráfico de temperatura, pressão e umidade e alguma análise)
