# watchCat
Запускать с админскими правами (su ./watchCat ...) 
Для работы понадобится либа для работы с портами (apt install libqt5serialport5)

Использование: ./watchCat [options]

Options:
  -p, --port <port_name>  назывние порта (например ttyACM0)
  -r, --response <sec>    Как часто дергать железку
  -t, --timeout <sec>     Таймаут до перезагрузки
  -v, --verbose           Мяфкать в консоль
  --pi, --portinfo        Показать список портов
  -h, --help              Displays this help.
