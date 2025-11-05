# 🔐 File Encryption & Decryption Tool (C)

## 📝 Project Description

This is a **File Encryption and Decryption Tool** developed in the **C programming language**.  
The main purpose of this project is to protect important data by converting it into an unreadable format (encryption) and later turning it back to its original form (decryption) using a secret key.

When you encrypt a file, the tool reads its contents, applies a secret key using XOR logic, and creates a new file with scrambled text.  
When you decrypt, it reads that encrypted file, applies the same key again, and restores the original readable text.

---

## ⚙️ How the Project Works

1. **You start the program** in VS Code or any C compiler.  
2. The program shows a menu with options:  
   - Encrypt a file  
   - Decrypt a file  
   - Exit  
3. You choose the option (1 or 2).  
4. Enter the input file name (for example, `input.txt`).  
5. Enter the output file name (for example, `encrypted.txt` or `decrypted.txt`).  
6. Enter any secret key (like `abc123`).  
7. The program processes the file and shows a success message.  

✔️ A file named `activity_log.txt` is also created automatically — it keeps a record of when and which files were encrypted or decrypted.

---

## 🧩 Files Created

- **main.c** → The main C source code file.  
- **input.txt** → Your original file (contains normal text).  
- **encrypted.txt** → Encrypted file (contains unreadable text).  
- **decrypted.txt** → Decrypted file (original readable text again).  
- **activity_log.txt** → Automatically created log file that saves activity details with date and time.  
- **README.md** → This file, which explains the project.  

---

## 🧠 Concepts Used

- File handling (`fopen`, `fread`, `fwrite`, `fclose`)  
- XOR encryption logic  
- Loops and conditions  
- String handling  
- Time and date logging  

---

## 🧰 How to Run the Project

1. Open your project folder `File_Encryption_Decryption_Tool` in **VS Code**.  
2. Open the **terminal** in VS Code (`Ctrl + ~`).  
3. Compile the code using GCC:
   ```bash
   gcc main.c -o encrypt_tool
