### 两个button
1. Start/Stop
2. Reset

### 状态转移

#### Stopped
1. 按下Reset，触发EvReset（复位）事件，状态仍然保持在 Stopped。
2. 按下Start/Stop，触发EvStartStop（开始/停止 计时事件），转移到 Running 状态

#### Running
1. 按下Reset，触发EvReset（复位）事件，转移到 Stopped 状态
2. 按下Start/Stop，触发EvStartStop（开始/停止 计时事件），转移到 Stopped 状态