# Simulasi Perencanaan Pensiun Menggunakan Metode Numerik Runge-Kutta Orde 4 (RK4)

## 👤 Informasi Mahasiswa
- **Nama**: Muhammad Hilmy Mahardika  
- **NPM**: 2306267006

## 🧮 Deskripsi Program
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
  `dW/dt = income + r × W`  
  dengan `r` adalah return riil dari investasi.

---

## 💻 Source Code

File source code ditulis dalam bahasa **C** dan diberi komentar di setiap proses agar mudah dipahami. File utama: `simulasi_pensiun_rk4.c`

---

## 📈 Contoh Output:
Program akan mencetak tabel pertumbuhan aset tiap tahun dan memberitahu kapan target kekayaan tercapai. Hasil bisa divisualisasikan menggunakan grafik seperti yang disediakan dalam laporan.

---

