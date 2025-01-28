#Automate the process of Compiling and running any C++ program

.PHONY: default build run clean

default:
        @echo "Specify command [build|run|clean] to execute."

build:
        @echo -n "Enter filename to compile: " && read FILENAME && { \
                if [ -f "$$FILENAME" ]; then \
                        g++ -o result "$$FILENAME" && echo "Compiled successfully."; \
                else \
                        echo "Error: File '$$FILENAME' does not exist."; \
                fi; \
        }

run:
        @if [ -f result ]; then \
                ./result; \
        else \
                echo "Error: No executable found. Run 'make build' first."; \
        fi

clean:
        @if [ -f result ]; then \
                rm -f result && echo "Executable removed."; \
        else \
                echo "No executable to remove."; \
        fi
