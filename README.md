# normfix — formatea y verifica (best‑effort) la Norm de 42

**Qué hace**  
- Aplica un formateo base con `clang-format` (.clang-format incluido) para acercarse al look&feel de la Norm: llaves estilo Allman, tabulaciones reales de 4, límite de 80 columnas, alineación de punteros pegada al nombre, etc.
- Luego pasa un *fixer* en Python que arregla detalles que `clang-format` no toca (por ejemplo `return (expr);`) y marca infracciones que no se pueden arreglar de forma segura (p.ej. funciones > 25 líneas, demasiados parámetros, uso de `for`/`switch`/ternario).

**Limitaciones**  
No es magia: hay reglas imposibles de corregir automáticamente sin romper la semántica (dividir funciones largas, sustituir ternarios por `if`, re‑estructurar VLAs, etc.). Para esas, el script te deja avisos en consola.

## Requisitos
- Python 3.10+
- `clang-format` en tu PATH (opcional pero recomendado). En Linux/Mac suele venir como `clang-format`; en Windows puedes instalarlo con LLVM. Si no está, el script seguirá pero solo hará los fixes propios.

## Uso
```bash
# 1) Descomprime el ZIP en la raíz de tu repo o en cualquier carpeta
# 2) Desde ahí, ejecuta (reemplaza 'src' por la carpeta de tus .c/.h):
python normfix.py src

# Modo verificación (no escribe archivos, solo reporta)
python normfix.py src --check

# Re-escribir todos los .c/.h in-place
python normfix.py src --write

# Elegir extensión
python normfix.py src --ext .c .h
```

El script aplica `.clang-format` de este directorio. Si ya tenías uno, compáralos.

## Qué corrige automáticamente (best‑effort)
- Indentación con tabulaciones reales (convierte sangrías iniciales de 4 espacios a `\t`).
- Llaves en línea propia (delegado a `clang-format`).
- Límite de 80 columnas (delegado a `clang-format`).
- `return expr;` → `return (expr);` sin tocar `return ;` ni `return (expr);` existentes.
- `char * str` → `char *str` (asterisco pegado al nombre del puntero).
- Un (y solo un) espacio tras comas y punto y coma (normalizado por `clang-format`).
- Una línea en blanco entre funciones; no más de una línea en blanco consecutiva.
- Evita espacios finales y líneas en blanco al final de archivo.

## Qué **marca** pero no repara
- Funciones con > 25 líneas (sin contar las llaves).
- Más de 4 parámetros en una función.
- > 5 variables declaradas por función.
- Comentarios dentro del cuerpo de función (te señala líneas sospechosas).
- Uso de `for`, `do...while`, `switch/case`, `goto`, operador ternario `? :`, VLAs.
- Más de 5 *definiciones* de función en un `.c`.
- Ficheros que no compilan (no se comprueba automáticamente, pero puedes integrar tu build en un hook).

## Integración como comando
Puedes crear un alias o añadirlo a un *pre-commit hook*:
```bash
# Linux/Mac
echo 'python "$(git rev-parse --show-toplevel)/normfix.py" src --write' > .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit
```

## Nota
Este proyecto pretende ayudarte a acelerar el 80% del trabajo mecánico. Las últimas reglas subjetivas tendrás que ajustarlas a mano durante la revisión.
