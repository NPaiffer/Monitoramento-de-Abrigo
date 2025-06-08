# Sistema de Monitoramento de Abrigos - Projeto IoT com ESP32, Node-RED e MQTT

Este projeto simula um sistema de monitoramento para abrigos de emergência em situações de enchente, utilizando o ESP32 como dispositivo IoT, Node-RED como gateway e painel de controle, e protocolo MQTT para troca de mensagens.

---

## ✅ Funcionalidades Implementadas

### 1. **Sistema IoT (ESP32)**
- Simula leitura de 3 dados:
  - Temperatura (ºC)
  - Umidade (%)
  - Nível da água (sensor analógico simulado)
- Liga um buzzer (simulado por LED) automaticamente em caso de nível crítico de água
- Recebe comandos remotos (ligar/desligar buzzer) via Node-RED

### 2. **Hardware**
- Utilizado o ESP32 no simulador Wokwi
- Buzzer simulado via LED conectado ao pino GPIO 13
- Link Wokwi: https://wokwi.com/projects/432284148593874945

### 3. **Dashboard Node-RED**
- Gauges e gráficos de histórico (chart) para todos os dados (temperatura, umidade, nível da água)
- Botão para controle manual do buzzer (liga/desliga)
- Alerta visual no painel em caso de enchente

### 4. **Gateway: Node-RED**
- Recebe dados MQTT
- Processa os dados e envia comandos
- Interface web com `node-red-dashboard`

### 5. **Protocolos**
- Comunicação entre ESP32 e Node-RED via **MQTT**
- Dados enviados em formato **JSON**
- Tópicos únicos e personalizados:
  - `enchentes/abrigos/abrigo01`
  - `enchentes/abrigos/abrigo01/buzzer`

---

## 🛠️ Como Executar o Projeto

### Pré-requisitos
- Node.js instalado: [https://nodejs.org](https://nodejs.org)
- Node-RED instalado:
  ```bash
  npm install -g node-red
  ```

### Passo a passo:

#### 1. Inicie o Node-RED
```bash
node-red
```

#### 2. Acesse o Editor
Abra no navegador:
```
http://localhost:1880
```

#### 3. Importe o Fluxo
- No editor, clique no menu ☰ > **Import**
- Cole o conteúdo do arquivo `fluxo-node-red.json`
- Clique em **Import** e depois em **Deploy**

#### 4. Acesse o Dashboard
Acesse a interface de monitoramento em:
```
http://localhost:1880/ui
```

---

## 🎯 Objetivo do Projeto

Este projeto foi desenvolvido como parte do desafio técnico de IoT, com o objetivo de aplicar conceitos de:
- Sensoriamento simulado
- Protocolos de comunicação (MQTT)
- Gateway e processamento de dados com Node-RED
- Visualização em tempo real
- Controle remoto de atuadores

---

Desenvolvido por 

Alissa Silva Cezero - RM552535
Melissa Barbosa de Souza - RM552535
Nicolas Paiffer do Carmo - RM554145.
