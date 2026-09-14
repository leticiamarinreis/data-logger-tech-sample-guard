# 🌡️ Sistema de Monitoramento Ambiental para Preservação de Amostras de Microscopia de Força Atômica (AFM)

## 📖 Sobre o Projeto
Este projeto foi desenvolvido para a disciplina de Sistemas Embarcados, do curso de Engenharia de Computação da Faculdade Engenheiro Salvador Arena.
O sistema consiste em um Data Logger Ambiental Inteligente, desenvolvido para monitorar e registrar as condições ambientais de armazenamento de amostras destinadas a análises por Microscopia de Força Atômica (AFM — Atomic Force Microscopy).
O dispositivo realiza o monitoramento contínuo de:
1. 🌡️ Temperatura;
💧 Umidade relativa do ar;
💡 Luminosidade;
🕐 Data e hora das medições.
Os dados coletados são processados pelo microcontrolador e armazenados em memória EEPROM, permitindo o acompanhamento histórico das condições às quais as amostras foram submetidas.
Além do registro das informações, o sistema possui uma Interface Homem-Máquina (IHM) baseada em display LCD e mecanismos de alerta visual e sonoro para indicar condições ambientais fora dos limites configurados.

## 🔬 Contexto da Aplicação
A Microscopia de Força Atômica (AFM) é uma técnica de caracterização de superfícies em escala nanométrica, amplamente utilizada em áreas como:
Nanotecnologia;
Ciência dos materiais;
Biomedicina;
Engenharia;
Pesquisa científica;
Caracterização de superfícies.
A qualidade e a confiabilidade das análises podem ser influenciadas pelo estado de conservação das amostras. Dependendo do material analisado, fatores ambientais podem provocar alterações físicas ou químicas capazes de interferir nos resultados experimentais.
Entre os fatores que podem ser relevantes durante o armazenamento estão:
Variações de temperatura;
Elevados níveis de umidade;
Exposição inadequada à luminosidade;
Oxidação de superfícies;
Contaminação ambiental;
Degradação ou alteração das propriedades do material.
Dessa forma, o monitoramento das condições de armazenamento pode contribuir para a rastreabilidade e a preservação das amostras antes da realização dos experimentos.
Observação: os limites considerados seguros para temperatura, umidade e luminosidade devem ser definidos de acordo com o tipo de amostra e os requisitos específicos do experimento. O sistema permite que esses limites sejam configurados conforme a aplicação.

## 🎯 Objetivo Geral
Desenvolver um sistema embarcado de monitoramento ambiental capaz de medir, registrar, armazenar e apresentar informações relacionadas às condições de armazenamento de amostras destinadas à Microscopia de Força Atômica.

## 🎯 Objetivos Específicos
O projeto possui os seguintes objetivos:
Monitorar a temperatura ambiente;
Monitorar a umidade relativa do ar;
Monitorar a luminosidade do ambiente;
Registrar as medições com data e hora;
Armazenar os dados em memória não volátil EEPROM;
Exibir informações em um display LCD 16x2 com interface I2C;
Detectar condições ambientais fora dos limites configurados;
Emitir alertas sonoros e visuais;
Desenvolver uma IHM simples e intuitiva;
Permitir a consulta do histórico das medições;
Demonstrar a aplicação prática de conceitos de sistemas embarcados e instrumentação eletrônica.

## 🌎 Problema
Durante o armazenamento de amostras destinadas a análises microscópicas, alterações nas condições ambientais podem afetar suas características e, consequentemente, influenciar os resultados obtidos posteriormente.
Sem um sistema de monitoramento contínuo, alterações ambientais podem passar despercebidas, dificultando a identificação das condições às quais determinada amostra esteve submetida.
Entre os possíveis efeitos estão:
Oxidação de superfícies;
Absorção de umidade;
Alterações estruturais;
Contaminação;
Degradação de materiais sensíveis;
Alterações de propriedades físicas e químicas.
O projeto busca contribuir para a rastreabilidade das condições ambientais de armazenamento, permitindo identificar possíveis variações e alertar o usuário quando parâmetros previamente definidos forem ultrapassados.

## 💡 Solução Proposta
A solução consiste em um sistema eletrônico embarcado baseado no microcontrolador ATmega328P.
O sistema realiza a aquisição, processamento, apresentação e armazenamento dos dados ambientais por meio dos seguintes componentes:

```text
              ┌─────────────────────┐
              │     Sensores        │
              │                     │
              │ DHT11 → Temperatura │
              │        → Umidade    │
              │                     │
              │ LDR  → Luminosidade │
              └──────────┬──────────┘
                         │
                         ▼
              ┌─────────────────────┐
              │     ATmega328P      │
              │                     │
              │ Processamento       │
              │ Controle            │
              │ Monitoramento       │
              └──────┬──────┬───────┘
                     │      │
            ┌────────┘      └────────┐
            ▼                        ▼
   ┌─────────────────┐      ┌─────────────────┐
   │      RTC        │      │     EEPROM      │
   │ Data e Hora     │      │ Armazenamento   │
   └─────────────────┘      │ dos registros   │
                            └─────────────────┘
                     │
                     ▼
              ┌─────────────────┐
              │    LCD 16x2     │
              │      I2C        │
              └─────────────────┘
                     │
                     ▼
              ┌─────────────────┐
              │ Alertas Sonoros │
              │   e Visuais     │
              └─────────────────┘
```

## ⚙️ Funcionamento
O sistema realiza um ciclo contínuo de monitoramento.
1. Aquisição
Os sensores realizam a leitura das condições ambientais:
DHT11: temperatura e umidade relativa do ar;
LDR: luminosidade do ambiente.
2. Processamento
O ATmega328P recebe os dados dos sensores e realiza o processamento das informações.
Os valores são comparados com os limites ambientais previamente configurados.
3. Registro de data e hora
Um módulo RTC (Real-Time Clock) fornece a data e a hora associadas a cada registro.
Isso permite relacionar cada medição ao momento exato em que foi realizada.
4. Armazenamento
As informações são armazenadas na EEPROM, uma memória não volátil que mantém os dados mesmo após o desligamento do sistema.
Um registro pode conter, por exemplo:
Data       Hora       Temperatura   Umidade   Luminosidade
14/09/2026 20:15:32   24,5 °C       52 %      680

5. Visualização
As informações são apresentadas ao usuário por meio de um display LCD 16x2 com comunicação I2C.
A interface permite visualizar os parâmetros monitorados e outras informações relevantes do sistema.
6. Alertas
Quando uma variável ultrapassa o limite configurado, o sistema pode acionar:
🔊 Alerta sonoro;
💡 Indicador visual;
⚠️ Mensagem de alerta na interface.

## 🧰 Componentes Utilizados
ComponenteFunçãoATmega328PProcessamento e controle do sistemaDHT11Medição de temperatura e umidadeLDRDetecção da intensidade luminosaRTCControle de data e horaEEPROMArmazenamento não volátil das mediçõesLCD 16x2 I2CInterface de visualizaçãoBuzzerAlerta sonoroLEDsIndicação visual de estadosFonte de alimentaçãoAlimentação do sistema

## 🖥️ Interface Homem-Máquina (IHM)
A IHM foi projetada para apresentar as informações de forma simples e objetiva.
Entre as informações que podem ser disponibilizadas estão:
TEMP: 24.5 C
UMID: 52 %

LUZ: 680
STATUS: NORMAL

Em situações de alerta:
!! ALERTA !!
UMIDADE ALTA

A interface pode ser expandida futuramente para permitir:
Configuração dos limites;
Consulta dos registros;
Navegação entre diferentes telas;
Visualização da data e hora;
Consulta do histórico armazenado.

## 💾 Armazenamento dos Dados
A utilização de memória EEPROM permite que os registros permaneçam armazenados mesmo quando o equipamento é desligado.
A estrutura dos registros pode ser organizada de forma semelhante a:

```text
┌────────────┬──────────┬─────────────┬─────────┬──────────────┐
│ Data       │ Hora     │ Temperatura │ Umidade │ Luminosidade │
├────────────┼──────────┼─────────────┼─────────┼──────────────┤
│ 14/09/2026 │ 20:15:32 │ 24.5 °C     │ 52 %    │ 680          │
└────────────┴──────────┴─────────────┴─────────┴──────────────┘
```

Essa abordagem permite construir um histórico das condições ambientais às quais as amostras estiveram submetidas.

## 🚨 Sistema de Alertas
O sistema compara continuamente os valores medidos com os limites definidos para a aplicação.
Exemplo:
ParâmetroCondiçãoAçãoTemperaturaAcima do limiteAlertaTemperaturaAbaixo do limiteAlertaUmidadeAcima do limiteAlertaLuminosidadeAcima do limiteAlertaTodosDentro dos limitesOperação normal

Os limites não são universais para todas as amostras e devem ser definidos de acordo com as características do material armazenado e os requisitos experimentais.

## 🔄 Fluxo de Funcionamento

```text
             INÍCIO
                │
                ▼
        Inicialização do
             sistema
                │
                ▼
        Leitura dos sensores
                │
                ▼
       Leitura do RTC
                │
                ▼
       Processamento dos
            dados
                │
                ▼
     ┌──────────────────────┐
     │ Valores estão dentro  │
     │ dos limites definidos?│
     └──────────┬───────────┘
                │
         ┌──────┴──────┐
         │             │
        SIM           NÃO
         │             │
         ▼             ▼
     Operação       Acionar
      normal        alerta
         │             │
         └──────┬──────┘
                │
                ▼
       Armazenar registro
           na EEPROM
                │
                ▼
        Atualizar o LCD
                │
                ▼
          Novo ciclo
                │
                └──────────►
```

## 📊 Benefícios
O sistema apresenta os seguintes benefícios:
🔬 Contribui para a preservação das amostras;
📈 Permite o acompanhamento histórico das condições ambientais;
🕐 Registra as medições associadas à data e hora;
🚨 Permite identificar condições fora dos limites estabelecidos;
💾 Mantém os dados armazenados em memória não volátil;
💰 Utiliza componentes de baixo custo;
🧑‍🔬 Facilita o acompanhamento por pesquisadores e técnicos;
⚙️ Demonstra conceitos de instrumentação e sistemas embarcados;
🔧 Possibilita futuras expansões de hardware e software.

## 🚀 Possíveis Melhorias Futuras
O projeto pode ser expandido para aplicações mais robustas por meio da inclusão de novas funcionalidades, como:
📡 Comunicação Wi-Fi ou Bluetooth;
☁️ Armazenamento dos dados em banco de dados ou plataforma IoT;
📱 Aplicativo para acompanhamento remoto;
📊 Geração automática de gráficos;
📧 Envio de notificações em situações de alerta;
💾 Utilização de cartão SD para maior capacidade de armazenamento;
🔋 Sistema de alimentação por bateria;
🌡️ Utilização de sensores de maior precisão;
🔐 Controle de acesso aos registros;
🖥️ Interface web para visualização do histórico;
📈 Análise estatística das condições ambientais;
⏱️ Configuração do intervalo entre as medições.

## 🧪 Aplicação Acadêmica
O projeto integra conceitos de diferentes áreas da Engenharia de Computação, incluindo:
Sistemas Embarcados;
Microcontroladores;
Eletrônica;
Instrumentação Eletrônica;
Sensoriamento;
Sistemas de aquisição de dados;
Comunicação I2C;
Memórias não voláteis;
Sistemas de tempo real;
Interface Homem-Máquina;
Monitoramento ambiental.

## 🏛️ Informações Acadêmicas
Instituição: Faculdade Engenheiro Salvador Arena
Curso: Engenharia de Computação
Disciplina: Sistemas Embarcados
Área: Instrumentação Eletrônica, Sistemas Embarcados e Monitoramento Ambiental
Aplicação: Monitoramento das condições de armazenamento de amostras para análises por AFM

## 👨‍💻 Projeto
Este projeto foi desenvolvido como parte das atividades acadêmicas da disciplina de Sistemas Embarcados, com o objetivo de aplicar conhecimentos de hardware e software na construção de uma solução de monitoramento ambiental.

## 📌 Considerações Finais
O Sistema de Monitoramento Ambiental para Preservação de Amostras de AFM apresenta uma solução embarcada de baixo custo para aquisição, registro e acompanhamento de variáveis ambientais relevantes ao armazenamento de amostras.
A utilização integrada de sensores, RTC, EEPROM, display LCD e mecanismos de alerta permite construir um sistema capaz de fornecer rastreabilidade das condições ambientais, contribuindo para um controle mais adequado do armazenamento e para a identificação de possíveis eventos que possam comprometer as amostras.
O projeto também estabelece uma base para futuras implementações envolvendo IoT, armazenamento em nuvem, monitoramento remoto e análise de dados, ampliando sua aplicabilidade em ambientes laboratoriais e de pesquisa.
