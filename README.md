# Tugas Besar 1 - IF2210 - OOP
<h2 align="center">
  🃏 Permainan Kartu ala Kerajaan Permen dengan Konsep OOP 🃏<br/>
</h2>
<hr>

## Table of Contents
1. [General Info](#general-information)
2. [Creator Info](#creator-information)
3. [Features](#features)
4. [Technologies Used](#technologies-used)
5. [Setup](#setup)
6. [Usage](#usage)
7. [Screenshots](#screenshots)
7. [Structure](#structure)
8. [Project Status](#project-status)
9. [Room for Improvement](#room-for-improvement)
10. [Acknowledgements](#acknowledgements)
11. [Contact](#contact)

<a name="general-information"></a>

## General Information
Permainan kartu ala kerajaan merupakan permainan yang terdiri atas 7 pemain. Pemain-pemain akan diberikan 2 kartu dan secara bergantian akan mencoba untuk membentuk kombinasi agar dapat memenangkan permainan. Poin awal tiap pemain adalah 64 dan akan bertambah atau berkurang seiring permainan. Pemain yang terlebih dahulu mendapatkan 2^32 poin akan memenangkan pertandingan. Projek ini digunakan untuk memenuhi tugas dari mata kuliah IF2210 - Pemrograman Berorientasi Objek yang ditulis dalam bahasa pemrograman C++.

<a name="creator-information"></a>

## Creator Information

| Nama                        | NIM      | E-Mail                      |
| --------------------------- | -------- | --------------------------- |
| Ahmad Ghulam Ilham          | 13521118 | 13521118@std.stei.itb.ac.id |
| Muhammad Naufal Nalendra    | 13521152 | 13521152@std.stei.itb.ac.id |
| Muhammad Dhiwaul Akbar      | 13521158 | 13521158@std.stei.itb.ac.id |
| Sulthan Dzaky Alfarozi      | 13521159 | 13521159@std.stei.itb.ac.id |
| Mohammad Rifqi Farhansyah   | 13521166 | 13521166@std.stei.itb.ac.id |
| Muhammad Habibi Husni       | 13521169 | 13521169@std.stei.itb.ac.id |

<a name="features"></a>

## Features
- Pemain dapat memberikan `input` untuk memilih `nama` yang akan digunakan dalam permainan.
- Pada setiap ronde, pemain dapat melakukan sebuah `command tertentu`.
- Di ronde pertama, pemain hanya dapat melakukan command `NEXT`.
- Pemain dapat melakukan command tertentu, kecuali command `ABILITY` yang tidak dimiliki oleh pemain tersebut.
- Setiap command yang dilakukan dan tidak valid, akan menghasilkan `error message` yang sesuai.

<a name="technologies-used"></a>

## Technologies Used
- Make 
- G++
> Note: The version of the libraries above is the version that we used in this project. You can use the latest version of the libraries.

<a name="setup"></a>

## Setup
1. Install `make` dan `g++` di dalam sistem Anda dengan cara:
```bash
sudo apt-get install make
sudo apt-get install g++
```
2. Apabila anda menggunakan `WSL` di dalam sistem Windows, maka anda dapat mengunduhnya melalui `Microsoft Store`.
3. Anda tetap harus menginstall `make` dan `g++` di dalam `WSL` sistem Anda dengan cara:
```bash
sudo apt-get install make
sudo apt-get install g++
```

<a name="usage"></a>

## Usage

#### LINUX
> Note: Untuk menjalankan program ini, Anda harus memiliki `make` dan `g++` yang sudah terinstall di dalam sistem Anda.
1. Clone repository [ini](https://github.com/rifqifarhansyah/Tubes1_OOP.git) ke dalam direktori lokal Anda, dengan cara:
```bash
git clone https://github.com/rifqifarhansyah/Tubes1_OOP.git
```
2. Masuk ke dalam direktori `Tubes1_OOP` yang telah Anda clone, dengan cara:
```bash
cd Tubes1_OOP
```
3. Jalankan program dengan makefile:
```bash
make
```
4. Apabila muncul pesan : `Enter folder:`, maka masukkan folder bernama `Game`.
5. Program akan berjalan.

#### WINDOWS (VS Code)
> Note: Untuk menjalankan program ini, pastikan anda memiliki `WSL` yang sudah terinstall di dalam sistem Anda.
1. Clone repository [ini](https://github.com/rifqifarhansyah/Tubes1_OOP.git) ke dalam direktori lokal Anda, dengan cara:
```bash
git clone https://github.com/rifqifarhansyah/Tubes1_OOP.git
```
2. Masuk ke dalam direktori `Tubes1_OOP` yang telah Anda clone, dengan cara:
```bash
cd Tubes1_OOP
```
3. Tekan `Ctrl + Shift + P` untuk membuka `Command Palette`.
4. Pilih `WSL: Reopen folder in WSL`.
5. Buat terminal baru pda VSCode.
6. Masukkan perintah berikut:
```bash
make
```
7. Apabila muncul pesan : `Enter folder:`, maka masukkan folder bernama `Game`.

<a name="screenshots"></a>

## Screenshots
<p>
  <img src="/image/SS1.png/">
  <p>Gambar 1. Awal Permainan</p>
  <nl>
  <img src="/image/SS2.png/">
  <p>Gambar 2. Input Nama Pemain</p>
  <nl>
  <img src="/image/SS3.png/">
  <p>Gambar 3. Notifikasi Pergantian Permainan dan Ronde</p>
  <nl>
  <img src="/image/SS4.png/">
  <p>Gambar 4. Exception Input Tidak Valid</p>
  <nl>
  <img src="/image/SS5.png/">
  <p>Gambar 5. Eksekusi Command</p>
  <nl>
</p>

<a name="structure"></a>

## Structure
```bash
│   .gitignore
│   main.cpp
│   makefile
│   README.md
│
├───.vscode
│       settings.json
│
├───config
│       config.txt
│
├───docs
│       IF2210_TB_HPC.pdf
│
├───image
│       SS1.png
│       SS2.png
│       SS3.png
│       SS4.png
│       SS5.png
│
└───lib
    ├───Ability
    │   │   Ability.cpp
    │   │   Ability.hpp
    │   │   Abilityless.cpp
    │   │   Abilityless.hpp
    │   │   Quadruple.cpp
    │   │   Quadruple.hpp
    │   │   Quarter.cpp
    │   │   Quarter.hpp
    │   │   ReRoll.cpp
    │   │   ReRoll.hpp
    │   │   ReverseDirection.cpp
    │   │   ReverseDirection.hpp
    │   │   SwapCard.cpp
    │   │   SwapCard.hpp
    │   │   SwitchCard.cpp
    │   │   SwitchCard.hpp
    │   │
    │   └───test
    │           AbilityTest.cpp
    │
    ├───AbstractClasses
    │   │   InventoryHolder.hpp
    │   │   ValuedObject.hpp
    │   │
    │   └───test
    │           InventoryHolderInt.hpp
    │           InventoryHolderTest.cpp
    │
    ├───Card
    │   │   Card.cpp
    │   │   Card.hpp
    │   │
    │   └───test
    │           Cardtest.cpp
    │
    ├───Combination
    │   │   Combination.cpp
    │   │   Combination.hpp
    │   │   Flush.cpp
    │   │   Flush.hpp
    │   │   FourOfAKind.cpp
    │   │   FourOfAKind.hpp
    │   │   FullHouse.cpp
    │   │   FullHouse.hpp
    │   │   HighCard.cpp
    │   │   HighCard.hpp
    │   │   Pair.cpp
    │   │   Pair.hpp
    │   │   Straight.cpp
    │   │   Straight.hpp
    │   │   StraightFlush.cpp
    │   │   StraightFlush.hpp
    │   │   ThreeOfAKind.cpp
    │   │   ThreeOfAKind.hpp
    │   │   TwoPair.cpp
    │   │   TwoPair.hpp
    │   │
    │   └───test
    │           CombinationTest.cpp
    │
    ├───Exception
    │       cardException.cpp
    │       cardExceptionInterface.hpp
    │       comboException.cpp
    │       comboExceptionInterface.hpp
    │       commandException.cpp
    │       commandExceptionInterface.hpp
    │       exception.cpp
    │       exceptionInterface.hpp
    │       fileException.cpp
    │       fileExceptionInterface.hpp
    │       inputException.cpp
    │       inputExceptionInterface.hpp
    │       inventoryException.cpp
    │       inventoryExceptionInterface.hpp
    │       playerCardException.cpp
    │       playerCardExceptionInterface.hpp
    │       tableCardException.cpp
    │       tableCardExceptionInterface.hpp
    │
    ├───Game
    │   │   Game.cpp
    │   │   Game.hpp
    │   │
    │   └───test
    │           GameTest
    │           GameTest.cpp
    │
    ├───IO
    │   │   command.cpp
    │   │   commandInterface.hpp
    │   │   consoleIO.cpp
    │   │   consoleIOInterface.hpp
    │   │
    │   └───test
    │           consoleIOTest.cpp
    │
    ├───MainDeck
    │   │   MainDeck.cpp
    │   │   MainDeck.hpp
    │   │
    │   └───test
    │           MainDeckTest.cpp
    │
    ├───Player
    │   │   Player.cpp
    │   │   Player.hpp
    │   │
    │   └───test
    │           PlayerTest.cpp
    │
    ├───TableCard
    │   │   TableCard.cpp
    │   │   TableCard.hpp
    │   │
    │   └───test
    │           TableCardTest.cpp
    │
    └───TemplateFunction
            TemplateFunction.hpp

```

<a name="project-status">

## Project Status
Project is: _complete_

<a name="room-for-improvement">

## Room for Improvement
- Menambahkan fitur-fitur lainnya.

<a name="acknowledgements">

## Acknowledgements
- Thanks To Allah SWT

<a name="contact"></a>

## Contact
<h4 align="center">
  Contact Us : HiperC++<br/>
  2023
</h4>
<hr>
