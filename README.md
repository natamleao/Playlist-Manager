# Playlist Manager em C

![Language](https://img.shields.io/badge/language-C-blue)
![Standard](https://img.shields.io/badge/standard-C11-orange)
![Build](https://img.shields.io/badge/build-Makefile-green)
![Data Structure](https://img.shields.io/badge/data_structure-linked_list-yellow)
![License](https://img.shields.io/badge/license-MIT-lightgrey)

---

## Sobre o projeto

> [!NOTE]
> Este projeto implementa um **gerenciador de playlist de músicas em C**, utilizando **lista encadeada circular** como estrutura de dados principal.

O sistema permite **armazenar, manipular e analisar músicas** dentro de uma playlist, oferecendo funcionalidades como:

* inserção
* remoção
* busca
* ordenação
* estatísticas
* leitura e escrita em arquivos

O objetivo principal do projeto é praticar **estruturas de dados, manipulação de ponteiros e organização modular de código em C**.

---

> [!IMPORTANT]
> ## Tecnologias utilizadas
>
> * **C (padrão C11)**
> * **GNU Make**
> * Estrutura de dados: **lista encadeada circular**

---

## Conceitos aplicados

Este projeto utiliza diversos conceitos fundamentais da linguagem C:

* Alocação dinâmica de memória (`malloc`, `free`)
* Manipulação de ponteiros
* Estrutura de dados: **lista encadeada**
* Encapsulamento utilizando arquivos `.h`
* Modularização do código
* Separação entre **interface e implementação**
* Manipulação de arquivos (`fopen`, `fscanf`, `fprintf`)
* Organização de projetos em múltiplos diretórios
* Automação da compilação com `Makefile`

---

## Funcionalidades

### Adicionar música

O sistema permite adicionar músicas à playlist de duas formas:

### Inserção manual

O usuário pode inserir músicas diretamente pelo terminal informando:

* nome da música
* nome do artista
* duração da música (em segundos)

### Leitura a partir de arquivo

Também é possível carregar músicas automaticamente a partir do arquivo **`musics.txt`**.

Formato esperado do arquivo:

```
Artista;Musica;Duracao
```

Exemplo:

```
Eminem;Lose Yourself;326
Coldplay;Viva La Vida;242
Adele;Rolling in the Deep;228
```

### Remover música

Remove uma música da playlist através do **nome da música**.

### Buscar música

Localiza uma música específica dentro da playlist.

### Ordenar playlist

Permite ordenar a playlist com base na **duração das músicas**.

### Salvar playlist em arquivo

Permite salvar todas as músicas da playlist em um arquivo `.txt`.

### Estatísticas da playlist

O sistema calcula:

* música mais longa
* música mais curta
* duração total da playlist
* duração média das músicas

### Executar playlist

Simula a reprodução da playlist percorrendo a lista circular.

O usuário pode escolher quantas vezes a playlist será reproduzida.

### Exibir playlist

Mostra todas as músicas armazenadas na playlist:

* nome da música
* artista
* duração

---

## Representação da estrutura de dados

A playlist é implementada utilizando **lista encadeada circular**.

```
HEAD
 ↓
[Music 1] → [Music 2] → [Music 3]
   ↑                          ↓
   └───────────────←──────────┘
```

Estrutura de cada nó:

```
struct _music{
    char *_musicName;
    char *_artistName;
    unsigned int _durationTime;
    struct _music *_next; 
};
```

---

## Estrutura do projeto

```
Playlist-Manager/
│
├── app/             # Arquivos principais da aplicação (main)
├── bin/             # Executáveis gerados
├── include/         # Arquivos de cabeçalho (.h)
├── obj/             # Arquivos objeto (.o)
├── src/             # Código-fonte da aplicação (.c)
│
├── Musics.txt       # Arquivo contendo as músicas para carregar
├── My Playlist.txt  # Arquivo que guarda as músicas salvas pelo usuário
│
├── Makefile         # Regras de compilação
├── README.md        # Documentação do projeto
└── LICENSE          # Licença do projeto
```

---

## Exemplo de execução

Exemplo de execução do programa no terminal:

```
+---------------------------------------------------------------------------+
+-------------------------------- BEM-VINDO --------------------------------+
+---------------------------------------------------------------------------+
+------------------------------ MENU PRINCIPAL -----------------------------+
+---------------------------------------------------------------------------+
+ 1 - ADICIONAR MÚSICA -----------------------------------------------------+
+---------------------------------------------------------------------------+
+ 2 - REMOVER MÚSICA -------------------------------------------------------+
+---------------------------------------------------------------------------+
+ 3 - BUSCAR MÚSICA --------------------------------------------------------+
+---------------------------------------------------------------------------+
+ 4 - ORDENAR PLAYLIST -----------------------------------------------------+
+---------------------------------------------------------------------------+
+ 5 - SALVAR PLAYLIST ------------------------------------------------------+
+---------------------------------------------------------------------------+
+ 6 - ESTATÍSTICAS ---------------------------------------------------------+
+---------------------------------------------------------------------------+
+ 7 - TOCAR PLAYLIST -------------------------------------------------------+
+---------------------------------------------------------------------------+
+ 8 - MOSTRAR PLAYLIST -----------------------------------------------------+
+---------------------------------------------------------------------------+
+ 0 - SAIR -----------------------------------------------------------------+
+---------------------------------------------------------------------------+
+ ESCOLHA UMA OPÇÃO: 
```

---

> [!IMPORTANT]
> ## Requisitos
>
> Para compilar e executar o projeto é necessário:
>
> * **GCC ou Clang**
> * **GNU Make**
> * Sistema **Linux ou macOS**

---

## Instalação

Clone o repositório:

```bash
git clone git@github.com:natamleao/Playlist-Manager.git
cd Playlist-Manager
```

---

## Compilação

Compile o projeto com:

```bash
make
```

---

## Execução

Execute o programa com:

```bash
make run
```

---

## Limpeza do projeto

Remover arquivos compilados:

```bash
make clean
make cleanapp
```

---

> [!WARNING]
> ## Licença
>
> Este projeto está licenciado sob a **Licença MIT**.

---

## Autor

**Natam Leão Ferreira**

Conclusão: **2026**

---
