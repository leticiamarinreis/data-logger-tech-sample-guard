# 🌡️ Sistema de Monitoramento Ambiental para Preservação de Amostras de Microscopia de Força Atômica (AFM)

## 📖 Sobre o Projeto
Este projeto foi desenvolvido para a disciplina de Sistemas Embarcados, do curso de Engenharia de Computação da Faculdade Engenheiro Salvador Arena.

O sistema consiste em um Data Logger Ambiental Inteligente, desenvolvido para monitorar e registrar as condições ambientais de armazenamento de amostras destinadas a análises por Microscopia de Força Atômica (AFM — Atomic Force Microscopy).

O dispositivo realiza o monitoramento contínuo de:

1. 🌡️ **Temperatura**;
2. 💧 **Umidade relativa do ar**;
3. 💡 **Luminosidade**;
4. 🕐 **Data e hora das medições**.
   
Os dados coletados são processados pelo microcontrolador e armazenados em memória EEPROM, permitindo o acompanhamento histórico das condições às quais as amostras foram submetidas.

Além do registro das informações, o sistema possui uma Interface Homem-Máquina (IHM) baseada em display LCD e mecanismos de alerta visual e sonoro para indicar condições ambientais fora dos limites configurados.

## 🔬 Contexto da Aplicação
A Microscopia de Força Atômica (AFM) é uma técnica de caracterização de superfícies em escala nanométrica, amplamente utilizada em áreas como:
1. **Nanotecnologia**;
2. **Ciência dos materiais**;
3. **Biomedicina**;
4. **Engenharia**;
5. **Pesquisa científica**;
6. **Caracterização de superfícies**.
   
A qualidade e a confiabilidade das análises podem ser influenciadas pelo estado de conservação das amostras. 

Dependendo do material analisado, fatores ambientais podem provocar alterações físicas ou químicas capazes de interferir nos resultados experimentais.

Entre os fatores que podem ser relevantes durante o armazenamento estão:
1. **Variações de temperatura**;
2. **Elevados níveis de umidade**;
3. **Exposição inadequada à luminosidade**;
4. **Oxidação de superfícies**;
5. **Contaminação ambiental**;
6. **Degradação ou alteração das propriedades do material**.
   
Dessa forma, o monitoramento das condições de armazenamento pode contribuir para a rastreabilidade e a preservação das amostras antes da realização dos experimentos.

**Observação**: os limites considerados seguros para temperatura, umidade e luminosidade devem ser definidos de acordo com o tipo de amostra e os requisitos específicos do experimento. O sistema permite que esses limites sejam configurados conforme a aplicação.

## 🎯 Objetivo Geral
Desenvolver um sistema embarcado de monitoramento ambiental capaz de medir, registrar, armazenar e apresentar informações relacionadas às condições de armazenamento de amostras destinadas à Microscopia de Força Atômica.

## 🎯 Objetivos Específicos
O projeto possui os seguintes objetivos:
1. **Monitorar a temperatura ambiente**;
2. **Monitorar a umidade relativa do ar**;
3. **Monitorar a luminosidade do ambiente**;
4. **Registrar as medições com data e hora**;
5. **Armazenar os dados em memória não volátil EEPROM**;
6. **Exibir informações em um display LCD 16x2 com interface I2C**;
7. **Detectar condições ambientais fora dos limites configurados**;
8. **Emitir alertas sonoros e visuais**;
9. **Desenvolver uma IHM simples e intuitiva**;
10. **Permitir a consulta do histórico das medições**;
11. **Demonstrar a aplicação prática de conceitos de sistemas embarcados e instrumentação eletrônica.**

## 🌎 Problema
Durante o armazenamento de amostras destinadas a análises microscópicas, alterações nas condições ambientais podem afetar suas características e, consequentemente, influenciar os resultados obtidos posteriormente.

Sem um sistema de monitoramento contínuo, alterações ambientais podem passar despercebidas, dificultando a identificação das condições às quais determinada amostra esteve submetida.

Entre os possíveis efeitos estão:
1. **Oxidação de superfícies**;
2. **Absorção de umidade**;
3. **Alterações estruturais**;
4. **Contaminação**;
5. **Degradação de materiais sensíveis**;
6. **Alterações de propriedades físicas e químicas.**
   
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

## ⚙️ Funcionamento do Sistema

O sistema opera em um ciclo contínuo de monitoramento dividido nas seguintes etapas:

1. **Aquisição:**
   - **DHT11:** Leitura da temperatura e umidade relativa do ar.
   - **LDR:** Leitura da luminosidade do ambiente.

2. **Processamento:**
   - O microcontrolador **ATmega328P** recebe os dados dos sensores e realiza o processamento das informações.
   - Os valores coletados são comparados com os limites ambientais previamente configurados no sistema.

3. **Registro de Data e Hora:**
   - Um módulo **RTC (Real-Time Clock)** fornece a data e a hora exatas associadas a cada registro.
   - Isso permite relacionar cada medição ao momento exato em que foi realizada.

4. **Armazenamento:**
   - As informações são armazenadas na **EEPROM**, uma memória não volátil que mantém os dados mesmo após o desligamento ou queda de energia do sistema.

5. **Visualização:**
   - As informações são apresentadas em tempo real através de um **Display LCD 16x2 com comunicação I2C**.
   - A interface permite visualizar os parâmetros monitorados e outras informações relevantes do sistema de forma clara.

6. **Alertas:**
   - Quando qualquer variável ultrapassa os limites configurados, o sistema aciona automaticamente:
     - 🔊 **Alerta Sonoro** (Buzzer);
     - 💡 **Indicador Visual** (LEDs de status/alerta);
     - ⚠️ **Mensagem de Alerta** diretamente na interface do display LCD.

## 🧰 Componentes Utilizados

| Componente | Função |
| :--- | :--- |
| **Fonte de alimentação** | Alimentação do sistema |
| **ATmega328P** | Processamento e controle do sistema |
| **DHT11** | Medição de temperatura e umidade |
| **LDR** | Detecção da intensidade luminosa |
| **RTC** | Controle de data e hora |
| **EEPROM** | Armazenamento não volátil das medições |
| **LCD 16x2 I2C** | Interface de visualização |
| **Buzzer** | Alerta sonoro |
| **LEDs** | Indicação visual de estados |

## 💻 Linguagens & Programação
- **C / C++ (Arduino Framework):** Linguagem principal utilizada para o desenvolvimento do firmware, controle de periféricos, lógica de processamento e gerenciamento da EEPROM.

## 🧰 Softwares & Ferramentas de Desenvolvimento
- **Arduino IDE:** Ambientes para desenvolvimento, compilação e upload do firmware.
- **TinkerCAD:** Simulação de circuitos eletrônicos e validação do código antes da montagem física.
- **GitHub:** Controle de versão e hospedagem do código-fonte do projeto.
- **Serial Monitor:** Leitura de logs e depuração dos dados transmitidos via comunicação Serial.

## 🖥️ Interface Homem-Máquina (IHM)
A IHM foi projetada para apresentar as informações de forma simples e objetiva.

Entre as informações que podem ser disponibilizadas estão:

| Estado do Sistema | Mensagem no Monitor Serial |
| :--- | :--- |
| **Operação Normal** | `TEMP: 24.5 C \| UMID: 52 % \| LUZ: 680 \| STATUS: NORMAL` |
| **Situação de Alerta** | `!! ALERTA !! UMIDADE ALTA` |


A interface pode ser expandida futuramente para permitir:
1. **Configuração dos limites**;
2. **Consulta dos registros**;
3. **Navegação entre diferentes telas**;
4. **Visualização da data e hora**;
5. **Consulta do histórico armazenado.**

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

| Parâmetro | Condição | Ação |
| :--- | :--- | :--- |
| **Temperatura** | Acima do limite | Alerta |
| **Temperatura** | Abaixo do limite | Alerta |
| **Umidade** | Acima do limite | Alerta |
| **Luminosidade** | Acima do limite | Alerta |
| **Todos** | Dentro dos limites | Operação normal |

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
     │Valores estão dentro  │
     │dos limites definidos?│
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
1. 🔬 **Contribui para a preservação das amostras**;
2. 📈 **Permite o acompanhamento histórico das condições ambientais**;
3. 🕐 **Registra as medições associadas à data e hora**;
4. 🚨 **Permite identificar condições fora dos limites estabelecidos**;
5. 💾 **Mantém os dados armazenados em memória não volátil**;
6. 💰 **Utiliza componentes de baixo custo**;
7. 🧑‍🔬 **Facilita o acompanhamento por pesquisadores e técnicos**;
8. ⚙️ **Demonstra conceitos de instrumentação e sistemas embarcados**;
9. 🔧 **Possibilita futuras expansões de hardware e software.**

## 🧪 Aplicação Acadêmica
O projeto integra conceitos de diferentes áreas da Engenharia de Computação, incluindo:
1. **Sistemas Embarcados**;
2. **Microcontroladores**;
3. **Eletrônica**;
4. **Instrumentação Eletrônica**;
5. **Sensoriamento**;
6. **Sistemas de aquisição de dados**;
7. **Comunicação I2C**;
8. **Memórias não voláteis**;
9. **Sistemas de tempo real**;
10. **Interface Homem-Máquina**;
11. **Monitoramento ambiental**.

## 🏛️ Informações Acadêmicas
**Instituição: Faculdade Engenheiro Salvador Arena**

**Curso: Engenharia de Computação**

**Disciplina: Sistemas Embarcados**

**Área: Instrumentação Eletrônica, Sistemas Embarcados e Monitoramento Ambiental**

**Aplicação: Monitoramento das condições de armazenamento de amostras para análises por AFM**

## 👨‍💻 Projeto
Este projeto foi desenvolvido como parte das atividades acadêmicas da disciplina de Sistemas Embarcados, com o objetivo de aplicar conhecimentos de hardware e software na construção de uma solução de monitoramento ambiental.

## 📌 Considerações Finais
O Sistema de Monitoramento Ambiental para Preservação de Amostras de AFM apresenta uma solução embarcada de baixo custo para aquisição, registro e acompanhamento de variáveis ambientais relevantes ao armazenamento de amostras.

A utilização integrada de sensores, RTC, EEPROM, display LCD e mecanismos de alerta permite construir um sistema capaz de fornecer rastreabilidade das condições ambientais, contribuindo para um controle mais adequado do armazenamento e para a identificação de possíveis eventos que possam comprometer as amostras.

O projeto também estabelece uma base para futuras implementações envolvendo IoT, armazenamento em nuvem, monitoramento remoto e análise de dados, ampliando sua aplicabilidade em ambientes laboratoriais e de pesquisa.
