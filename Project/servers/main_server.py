import os

def run_in_terminal(file_path):
    command = f'python {file_path}'
    os.system(command)

def run_all_python_files(directories):
    for directory in directories:
        for filename in os.listdir(directory):
            if filename.endswith('.py'):
                file_path = os.path.join(directory, filename)
                run_in_terminal(file_path)

if __name__ == "__main__":
    directories = ['homenews', 'livescore', 'servers']
    run_all_python_files(directories)
