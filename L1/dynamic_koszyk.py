import os
import re

# --- KONFIGURACJA ---
imie_nazwisko = "Krzysztof_Zdzieszynski" 
base_path = os.path.dirname(os.path.abspath(__file__)) 

nr_lab = input("Podaj numer laboratorium (np. 1): ")
root_folder = os.path.join(base_path, f"L{nr_lab}")
output_filename = os.path.join(base_path, f"{imie_nazwisko}_l{nr_lab}.txt")

# NOWA, BEZPIECZNA FUNKCJA SORTUJĄCA
# Zamienia liczby w tekście na 10-cyfrowe bloki (np. "Zadanie 2" -> "Zadanie 0000000002")
def safe_sort_key(text):
    return re.sub(r'\d+', lambda m: m.group(0).zfill(10), text.lower())

# Korekta ścieżki (jeśli skrypt jest w L1)
if not os.path.exists(root_folder) and os.path.basename(base_path) == f"L{nr_lab}":
    root_folder = base_path

def generuj_sprawozdanie():
    if not os.path.exists(root_folder):
        print(f"Błąd: Nie znaleziono folderu '{root_folder}'.")
        return

    try:
        # Pobieramy i sortujemy foldery
        all_entries = os.listdir(root_folder)
        folders = [d for d in all_entries if os.path.isdir(os.path.join(root_folder, d))]
        folders.sort(key=safe_sort_key)

        with open(output_filename, "w", encoding="utf-8") as f_out:
            f_out.write(f"PROGRAMOWANIE OBIEKTOWE - LABORATORIUM NR {nr_lab}\n")
            f_out.write(f"AUTOR: Krzysztof Zdzieszynski\n")
            f_out.write("="*60 + "\n\n")

            licznik_zadan = 0

            for folder in folders:
                folder_path = os.path.join(root_folder, folder)
                files_in_folder = os.listdir(folder_path)
                
                # Sortujemy pliki bezpieczną metodą
                cpp_files = sorted([f for f in files_in_folder if f.endswith(".cpp")], key=safe_sort_key)
                txt_files = sorted([f for f in files_in_folder if f.endswith(".txt")], key=safe_sort_key)

                if cpp_files or txt_files:
                    licznik_zadan += 1
                    f_out.write(f"// >>> ROZDZIAL: {folder} <<<\n")
                    f_out.write("*" * 60 + "\n\n")
                
                    for cpp in cpp_files:
                        f_out.write(f"// PLIK ZRODLOWY: {cpp}\n")
                        f_out.write("-" * 40 + "\n")
                        with open(os.path.join(folder_path, cpp), "r", encoding="utf-8", errors="replace") as f_in:
                            f_out.write(f_in.read().strip())
                        f_out.write("\n\n")

                    for txt in txt_files:
                        if txt == os.path.basename(output_filename): continue
                        f_out.write(f"// ZALACZNIK (DANE/WYNIK/OPIS): {txt}\n")
                        f_out.write("." * 40 + "\n")
                        with open(os.path.join(folder_path, txt), "r", encoding="utf-8", errors="replace") as f_in:
                            f_out.write(f_in.read().strip())
                        f_out.write("\n\n")
                    
                    f_out.write("/" * 60 + "\n\n")

        print(f"\nSukces! Wygenerowano: {os.path.basename(output_filename)}")
        print(f"Przetworzono zadań: {licznik_zadan}")

    except Exception as e:
        print(f"Wystąpił błąd krytyczny: {e}")

if __name__ == "__main__":
    generuj_sprawozdanie()
