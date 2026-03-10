import os
import re

# folder główny z zadaniami
folder = r"C:\Users\HP\OneDrive\Pulpit\obiektowe zadania"

# plik wyjściowy w tym samym folderze
plik_wy = os.path.join(folder, "wszystkie_zadania.txt")

# lista wszystkich plików cpp w podfolderach
pliki = []
for root, dirs, files in os.walk(folder):
    for f in files:
        if f.lower().endswith(".cpp"):
            pliki.append(os.path.join(root, f))

# funkcja do wyciągania numeru zadania z nazwy folderu lub pliku
def numer_zadania(sciezka):
    match = re.search(r'\d+', sciezka)
    return int(match.group()) if match else 0

# sortowanie według numeru zadania
pliki.sort(key=numer_zadania)

# zapis do pliku txt
with open(plik_wy, "w", encoding="utf-8") as out:
    for i, sciezka_pliku in enumerate(pliki, start=1):
        out.write(f"===== Zadanie {i} =====\n")
        with open(sciezka_pliku, "r", encoding="utf-8") as f:
            zawartosc = f.read()
            out.write(zawartosc + "\n\n")

print(f"Zawartość wszystkich zadań została zapisana w: {plik_wy}")