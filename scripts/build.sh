#!/bin/bash

# MVF Build Script
# Usage: ./scripts/build.sh [install|clean|check]

set -e  # Exit on error

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$PROJECT_ROOT"

echo "🔨 MVF Build Script"
echo "📁 Project root: $PROJECT_ROOT"
echo

case "${1:-build}" in
    "build")
        echo "🏗️  Building MVF..."
        make clean
        make
        echo "✅ Build complete!"
        ;;
    
    "install")
        echo "🏗️  Building and installing MVF..."
        make clean
        make
        make install
        echo "✅ Installation complete!"
        ;;
    
    "clean")
        echo "🧹 Cleaning build artifacts..."
        make clean
        echo "✅ Clean complete!"
        ;;
    
    "check")
        echo "🔍 Checking installation..."
        make check
        ;;
    
    "help"|"-h"|"--help")
        echo "Usage: $0 [command]"
        echo
        echo "Commands:"
        echo "  build     - Build the project (default)"
        echo "  install   - Build and install system-wide"
        echo "  clean     - Clean build artifacts"
        echo "  check     - Check if mvf is installed"
        echo "  help      - Show this help message"
        ;;
    
    *)
        echo "❌ Unknown command: $1"
        echo "Run '$0 help' for usage information."
        exit 1
        ;;
esac 