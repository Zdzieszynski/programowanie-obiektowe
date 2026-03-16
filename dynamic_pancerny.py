import os
import sys

# --- DANE STAŁE ---
AUTOR = "Krzysztof Zdzieszyński"
KIERUNEK = "informatyka"
GRUPA = "L2"

# --- PYTANIA POCZĄTKOWE ---
print("=== KREATOR SPRAWOZDANIA (STABILNY I PROSTY) ===")

# Czytamy wejście i upewniamy się, że Python traktuje je jako tekst
def bezpieczny_input(prompt):
    try:
        data = input(prompt)
        # Naprawa kodowania dla Windows (zamiana błędnych bajtów na znaki zapytania)
        return data.encode('utf-8', 'replace').decode('utf-8')
    except EOFError:
        return ""

nr_lab = bezpieczny_input("Podaj numer laboratorium (np. 3): ").strip()
temat_lab = bezpieczny_input("Podaj temat zajęć: ").strip()

root_folder = f"L{nr_lab}" 
tex_output = os.path.join(root_folder, "main.tex")

if not os.path.exists(root_folder):
    print(f"BŁĄD: Folder {root_folder} nie istnieje!")
    exit()

def is_image(file):
    return file.lower().endswith((".png", ".jpg", ".jpeg"))

# --- GENEROWANIE PLIKU .TEX ---
with open(tex_output, "w", encoding="utf-8") as texf:
    # Preambuła zgodna z Twoim wzorem
    texf.write(f"""\\documentclass[12pt,a4paper]{{article}}
\\usepackage[polish]{{babel}}
\\usepackage[T1]{{fontenc}}
\\usepackage[utf8]{{inputenc}}
\\usepackage{{hyperref}}
\\usepackage{{url}}
\\usepackage{{graphicx}}
\\usepackage{{listingsutf8}}
\\usepackage{{xcolor}}

% Marginesy wzorcowe
\\addtolength{{\\hoffset}}{{-1.5cm}}
\\addtolength{{\\marginparwidth}}{{-1.5cm}}
\\addtolength{{\\textwidth}}{{3cm}}
\\addtolength{{\\voffset}}{{-1cm}}
\\addtolength{{\\textheight}}{{2.5cm}}
\\setlength{{\\topmargin}}{{0cm}}
\\setlength{{\\headheight}}{{0cm}}

\\lstset{{
    inputencoding=utf8,
    basicstyle=\\ttfamily\\small,
    breaklines=true,
    keepspaces=true,
    columns=flexible,
    tabsize=4,
    showstringspaces=false,
    frame=single,
    extendedchars=true,
    literate={{ą}}{{\\k{{a}}}}1 {{ć}}{{\\'c}}1 {{ę}}{{\\k{{e}}}}1 {{ł}}{{\\l{{}}}}1 {{ń}}{{\\'n}}1 {{ó}}{{\\'o}}1 {{ś}}{{\\'s}}1 {{ź}}{{\\z}}1 {{ż}}{{\\.z}}1
             {{Ą}}{{\\k{{A}}}}1 {{Ć}}{{\\'C}}1 {{Ę}}{{\\k{{E}}}}1 {{Ł}}{{\\L{{}}}}1 {{Ń}}{{\\'N}}1 {{Ó}}{{\\'O}}1 {{Ś}}{{\\'S}}1 {{Ź}}{{\\z}}1 {{Ż}}{{\\.Z}}1
}}

\\title{{{temat_lab} (Lab {nr_lab})}}
\\author{{{AUTOR} \\\\ Kierunek: {KIERUNEK} \\\\ Grupa: {GRUPA}}}
\\date{{\\today}}

\\begin{{document}}
\\maketitle
\\tableofcontents
\\listoffigures
\\newpage

\\section{{Realizacja zadań}}
""")

    zadania = sorted([d for d in os.listdir(root_folder) if os.path.isdir(os.path.join(root_folder, d))])
    
    for i, zadanie_folder in enumerate(zadania, start=1):
        folder_path = os.path.join(root_folder, zadanie_folder)
        print(f"\n>>> Zadanie: {zadanie_folder}")
        
        # Bezpieczne wczytanie opisu z klawiatury
        dodatkowy_opis = bezpieczny_input(f"Dodatkowe uwagi do {zadanie_folder} (lub ENTER): ").strip()
        
        texf.write(f"\\subsection*{{Zadanie {i}: {zadanie_folder}}}\n")

        # Szukanie i konwersja plików tekstowych
        for filename in os.listdir(folder_path):
            if filename.lower() == f"{zadanie_folder.lower()}.txt":
                txt_path = os.path.join(folder_path, filename)
                content = ""
                for enc in ['utf-8', 'cp1250', 'iso-8859-2']:
                    try:
                        with open(txt_path, "r", encoding=enc) as f:
                            content = f.read()
                        break
                    except: continue
                
                # Zawsze zapisujemy w UTF-8
                with open(txt_path, "w", encoding="utf-8") as f:
                    f.write(content)
                
                texf.write("\\textbf{Opis zadania:}\\\\\n")
                texf.write(content.strip() + "\n\n")
                break

        # Przetwarzanie plików .py
        py_files = sorted([p for p in os.listdir(folder_path) if p.endswith(".py")])
        for py in py_files:
            py_path = os.path.join(folder_path, py)
            code = ""
            for enc in ['utf-8', 'cp1250', 'windows-1250']:
                try:
                    with open(py_path, "r", encoding=enc) as f:
                        code = f.read()
                    break
                except: continue
            
            with open(py_path, "w", encoding="utf-8") as f:
                f.write(code)

            texf.write(f"\\textbf{{Kod źródłowy: {py}}}\n")
            texf.write(f"\\lstinputlisting[inputencoding=utf8]{{{zadanie_folder}/{py}}}\n\n")
        
        if dodatkowy_opis:
            texf.write(f"\\textbf{{Analiza:}}\\\\\n{dodatkowy_opis}\n\n")

        # Obrazki
        images = [p for p in sorted(os.listdir(folder_path)) if is_image(p)]
        for img in images:
            path = f"{zadanie_folder}/{img}"
            texf.write(r"\begin{figure}[h!]\centering" + "\n")
            texf.write(f"  \\includegraphics[width=0.7\\textwidth]{{{path}}}\n")
            texf.write(f"  \\caption{{Zrzut ekranu: {img}}}\n")
            texf.write(r"\end{figure}" + "\n")
        
        texf.write("\\newpage\n")

    texf.write("\\end{document}")

print(f"\n[SUKCES] Wygenerowano main.tex.")
