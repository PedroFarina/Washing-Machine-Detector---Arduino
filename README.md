# Steady Vibration Detection
This project idea came from the day I spent the whole day coding and forgetting about my washed laundry from 9AM to 9PM. A simple HomeKit integration with HomeSpan alongside an ESP32 + SW-420 which:

- Waits for a vibration to be detected
- Once it detects the first vibration spends 5 minutes making sure the vibrations are constants (if it stops for more than 45s it goes back to Idle)
- Once it makes sure that it's indeed something repetitive vibrating going on it wait after 4 minutes of not vibrating anymore to trigger a Motion Detected on HomeKit app

It's clearly mainly focused at a laundry washing machine but you're free to use it as you wish!
