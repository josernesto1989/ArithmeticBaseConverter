# ArithmeticBaseConverter (ABC)

Aplicación de escritorio para convertir números enteros entre bases numéricas. Permite escribir un número en una base de origen y consultar sus conversiones a las bases añadidas a la tabla.

## Características

- Conversión de números enteros entre bases del 2 al 36.
- Base de origen seleccionable.
- Adición de bases de destino para mostrar varias conversiones a la vez.
- Interfaz gráfica construida con Qt Widgets.

## Requisitos

- CMake 3.5 o posterior.
- Un compilador compatible con C++17.
- Qt 5 o Qt 6, con el módulo **Widgets**.

## Compilar

Desde la raíz del repositorio, configura y compila el proyecto:

```sh
cmake -S . -B build
cmake --build build
```

Si CMake no encuentra Qt automáticamente, indica la ruta de instalación de Qt al configurar. Por ejemplo:

```sh
cmake -S . -B build -DCMAKE_PREFIX_PATH=/ruta/a/Qt
cmake --build build
```

El ejecutable se genera dentro de `build/`. En macOS, el proyecto se empaqueta como `ArithmeticBaseConverter.app`.

## Uso

1. Escribe un número entero en el campo de entrada.
2. Selecciona la base en la que está escrito el número.
3. Añade una o más bases de destino introduciendo cada valor y pulsando **Addicionar conversion**.
4. Consulta en la tabla el número convertido para cada base añadida.

Usa bases entre **2 y 36**. Los dígitos alfabéticos representan los valores del 10 al 35 (`a`–`z`, sin distinguir mayúsculas y minúsculas). La aplicación convierte enteros; una entrada inválida para la base seleccionada no produce una conversión válida.

## Tecnologías

- C++17
- Qt Widgets (Qt 5 o Qt 6)
- CMake

## Estructura del proyecto

- `main.cpp`: punto de entrada de la aplicación.
- `mainwindow.*`: ventana principal y conexión de la interfaz con los modelos.
- `basesmanager.*`: gestión de bases y lógica de conversión.
- `basesitemmodel.*`: modelo de datos de la tabla.
- `mainwindow.ui`: diseño de la interfaz Qt.
- `assets/app-icon.svg`: diseño fuente del icono de calculadora binaria.
- `assets/app-icon.png`, `assets/app-icon.icns` y `assets/app-icon.ico`: iconos de aplicación para Qt, macOS y Windows.
- `CMakeLists.txt`: configuración de compilación.
