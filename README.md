# Environment Meter Dragon

### Sobre
   1.1 Medidor climático realizado durante a disciplina de Computação Física e Aplicações da graduação de Sistemas de Informação sob orientação do professor Fábio Nakano. Realizado com a colaboração de Laura Steinert de Freitas.
   
   1.1. Como?
   
   Usando ESP32, um sensor medidor climático, BME280, e uma fita de 10 LEDs, com comunicação direta com um aplicativo desenvolvido pelo AppInventor através do banco de dados ThingSpeak. O aplicativo apresenta dados como temperatura, umidade, pressão atmosférica e altitude, que, de acordo com seus valores, alteram a coloração do dragçao.
 
 ### Aparência
 
 ##
 
 ![Dragão de plástico branco](https://user-images.githubusercontent.com/47001648/151721537-f6594971-32e2-424c-8294-f69e5597974b.png)

  
  ### 1.2 Infraestrutura
  
  ## 
  
  #### 1.2.1 Visão geral
  
  ##### 1.2.2 Dispositivo - Dragão Meteorológico
  
  &emsp; 1.2.2.1 Lista de peças
         
  &emsp;  &emsp;  &emsp;Sensor ESP32, BME280, Fita de LEDs, Jumpers.
  
  &emsp;  &emsp;  &emsp;Para o dragão: Filamento PLA Transparente 1.75mm, Impressora 3D Ender-3 Pro - Creality.
               
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
   
   &emsp;  &emsp; &emsp;  &emsp; A impressão foi realizada pela Impressora 3D Ender-3 Pro - Creality, e foram utilizados em torno de 435 gramas de Filamento PLA Transparente de 1.75mm, levando cerca de 56h de impressão, com alguns defeitos mínimos e pontuais.
   
   &emsp;  &emsp; &emsp;  &emsp; Referência de projeto: ThingVerse, thing 1624412 - **https://www.thingiverse.com/thing:1624412**

   ##### 1.2.4  Visualização: impressão 3D
   
   &emsp;  &emsp; &emsp;  &emsp; Em conjunto com a disciplina de Computação Física e Aplicações, o protótipo foi pensado em uma colaboração com o [Lab das Minas](https://www.instagram.com/labdasminas/), grupo de pesquisa dHumanidades da Universidade de São Paulo (EACH-USP) com foco em inserção de adolescentes de 11 a 17 anos na ciência e na tecnologia - utilizando do ensino da robótica, por muitas vezes. Por ser um projeto elucidativo, com uso da placa ESP32 e da impressão 3D com respostas visuais do funcionamento do código, a estratégia pensada foi utilizá-lo de apoio para próximos ensinamentos conduzidos pelo grupo. Tendo isso em vista, as respostas visuais dos LEDs variam de acordo com as métricas do sensor, piscando primeiro para valores da temperatura, depois para umidade, por último, para altitude. Os parâmetros utilizados foram: 
   
      - Temperatura: acima de 30ºC, LEDs vermelhos; Entre 30ºC e 20ºC, LEDs verdes; Abaixo de 20ºC, LEDs azuis.
      - Umidade: abaixo de 25%: LEDs vermelhos; Entre 50 e 80%, LEDs verdes; Acima de 80%, LEDs azuis.
      - Altitude: abaixo de 800 metros com relação ao nível do mar: LEDs azuis; Entre 800 e 3000 metros, LEDs verdes; Acima de 3000 metros: LEDs amarelos.
   
   ##### 1.2.5  Visualização: aplicativo
   
   &emsp;  &emsp; 1.2.5.1 Visão geral, proposta geral
   
   &emsp;  &emsp;&emsp; 1.2.5.2 Aplicativo
   
   ##### 1.2.6  Banco de dados: ThingSpeak
   
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
