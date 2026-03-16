import os

# --- KONFIGURACJA UŻYTKOWNIKA ---
imie_nazwisko = "Krzysztof_Zdzieszynski" # Wersja bez polskich znaków dla bezpieczeństwa systemu

# Interakcja: Wprowadzasz numer, np. "3"
nr_lab = input("Podaj numer laboratorium (np. 3): ")

# Ustawienia ścieżek
root_folder = f"L{nr_lab}"
output_filename = f"{imie_nazwisko}_l{nr_lab}.txt"

def generuj_sprawozdanie():
    # Sprawdzenie czy folder (np. L3) istnieje
    if not os.path.exists(root_folder):
        print(f"Błąd: Nie znaleziono folderu źródłowego '{root_folder}'.")
        return

    try:
        with open(output_filename, "w", encoding="utf-8") as f_out:
            # Nagłówek wewnątrz pliku (tutaj możemy użyć polskich znaków)
            f_out.write(f"PROGRAMOWANIE OBIEKTOWE - LABORATORIUM NR {nr_lab}\n")
            f_out.write(f"AUTOR: Krzysztof Zdzieszyński\n")
            f_out.write("="*60 + "\n\n")

            # Sortujemy foldery zadań (Zadanie1, Zadanie2...)
            folders = sorted([d for d in os.listdir(root_folder) if os.path.isdir(os.path.join(root_folder, d))])

            for folder in folders:
                folder_path = os.path.join(root_folder, folder)
                
                # Szukamy wyłącznie plików .cpp
                cpp_files = sorted([f for f in os.listdir(folder_path) if f.endswith(".cpp")])

                if cpp_files:
                    for cpp in cpp_files:
                        # Nagłówek sekcji dla konkretnego pliku
                        f_out.write(f"// >>> SEKCJA: {folder} | PLIK: {cpp} <<<\n")
                        f_out.write("-" * 60 + "\n")
                        
                        cpp_path = os.path.join(folder_path, cpp)
                        try:
                            with open(cpp_path, "r", encoding="utf-8", errors="replace") as f_in:
                                f_out.write(f_in.read().strip())
                        except Exception as e:
                            f_out.write(f"// Błąd odczytu pliku: {e}")
                        
                        # Separator między zadaniami
                        f_out.write("\n\n" + "/"*60 + "\n\n")

        print(f"\nSukces! Plik wygenerowany: {output_filename}")

    except Exception as e:
        print(f"Wystąpił błąd podczas zapisu: {e}")

if __name__ == "__main__":
    generuj_sprawozdanie()
