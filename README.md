# Integrantes: <br>
Alissa Silva Cezero - RM552535 <br> Melissa Barbosa de Souza - RM552535 <br> Nicolas Paiffer do Carmo - RM554145

# Sistema IoT para Monitoramento de Abrigo contra Enchentes 🌧️🏠

Este projeto tem como objetivo monitorar e alertar sobre condições críticas em abrigos para vítimas de enchentes, utilizando ESP32, MQTT e Node-RED.

## 🔧 Tecnologias e Ferramentas

- **Microcontrolador**: ESP32 (simulado via [Wokwi](https://wokwi.com))
- **Gateway**: Node-RED (com `node-red-dashboard`)
- **Broker MQTT**: HiveMQ
- **Dashboard**: Visualização em tempo real com gráficos e botões de controle
- **Comunicação**: Protocolo MQTT (mensagens em JSON)

## 📦 Funcionalidades

- Simulação de sensores de:
  - Temperatura (°C)
  - Umidade (%)
  - Nível da água (0 a 4095)
- Atuação automática com **buzzer** em caso de enchente
- Controle **manual** do buzzer via botão no painel
- Visualização **gráfica** em tempo real dos dados no dashboard
- Publicação e assinatura de tópicos MQTT personalizados

## 🧩 Estrutura MQTT

- Publicação de dados: `enchentes/abrigos/abrigo01`
- Controle do buzzer: `enchentes/abrigos/abrigo01/buzzer`

## 📈 Dashboard (Node-RED)

- Gráficos históricos para temperatura, umidade e nível da água
- Botão para ligar/desligar manualmente o buzzer
- Indicadores visuais com `gauges`

---

Desenvolvido como parte do projeto de IoT para monitoramento comunitário em áreas de risco de enchentes no Brasil.
