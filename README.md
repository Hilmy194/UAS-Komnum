# Simulasi Perencanaan Pensiun Menggunakan Metode Numerik Runge-Kutta Orde 4 (RK4)

- **Nama**: Muhammad Hilmy Mahardika  
- **NPM**: 2306267006

## Deskripsi Program
Program ini melakukan simulasi perencanaan pensiun untuk menentukan usia berapa seseorang dapat mencapai kebebasan finansial (financial freedom), berdasarkan prinsip **compound interest**, **aturan 4%**, dan menggunakan metode numerik **Runge-Kutta Orde 4 (RK4)**.

### ✨ Fitur Program:
- Menghitung pertumbuhan aset tahunan berdasarkan gaji, persentase tabungan, dan return investasi
- Menghitung target kekayaan pensiun berdasarkan target pengeluaran tahunan × 25 (4% rule)
- Menentukan tahun dan umur saat target kekayaan tercapai

### 📌 Input yang Diminta:
- Usia saat ini
- Gaji tahunan saat ini
- Persentase tabungan (% dari gaji)
- Aset awal (jika ada)
- Target pengeluaran tahunan saat pensiun

### ⚙️ Metode yang Digunakan:
- **Runge-Kutta Orde 4 (RK4)** digunakan untuk menyelesaikan model ODE dari perubahan aset per tahun:  
  ![](https://imgur.com/xEdlkQX.png)

    Dengan: 
    - W(t): kekayaan pada tahun ke-t
    - s: rasio tabungan dari gaji
    - G(t): gaji tahunan, naik sesuai inflasi
    - r: return investasi riil tahunan

- Model Runge-Kutta orde 4 (RK4):

![](https://imgur.com/Z5LZdon.png)
![](https://imgur.com/veClL9R.png)

---

## 📈 Contoh Output:
Program akan mencetak tabel pertumbuhan aset tiap tahun dan memberitahu kapan target kekayaan tercapai. Hasil bisa divisualisasikan menggunakan grafik seperti yang disediakan dalam laporan.

### Tabel
![tabel](https://imgur.com/XVF3kqZ.png)

![tabel](https://imgur.com/IhwFsc9.png)

### Grafik:
![grafik](https://imgur.com/CuqpJX5.png)
---

