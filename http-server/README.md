# Minimal HTTP Server

Server HTTP minimale scritto in C. Risponde con il contenuto di `public/index.html` per tutte le richieste GET.

## 📦 Requisiti

- GCC compatibile con lo standard C11
- Sistema POSIX (Linux/macOS)
- `make` (opzionale per build facilitata)

## 🚀 Avvio Rapido

git clone https://github.com/bocaletto-luca/c-example/http-server.git
cd http-server
make
./http-server

## Struttura

http-server/
├── Makefile
├── public/
│   └── index.html
└── src/
    └── server.c
