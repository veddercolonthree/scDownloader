#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORANGE "\033[38;2;255;165;0m"
#define RESET "\033[0m"

void title() {
    printf("%s         _ _____                      _                 _           \n", ORANGE);
    printf("        | |  __ \\                    | |               | |          \n");
    printf(" ___  __| | |  | | _____      ___ __ | | ___   __ _  __| | ___ _ __ \n");
    printf("/ __|/ _` | |  | |/ _ \\ \\ /\\ / / '_ \\| |/ _ \\ / _` |/ _` |/ _ \\ '__|\n");
    printf("\\__ \\ (_| | |__| | (_) \\ V  V /| | | | | (_) | (_| | (_| |  __/ |   \n");
    printf("|___/\\__,_|_____/ \\___/ \\_/\\_/ |_| |_|_|\\___/ \\__,_|\\__,_|\\___|_|   \n");
    printf("%s\n", RESET);
}

void metadata(){
    return;
}

void download(){
    char url[256];
    printf("Enter SoundCloud URL: ");
    scanf("%255s", url);

    char command[512];
    snprintf(command, sizeof(command), "yt-dlp -f bestaudio -x --audio-format mp3 --audio-quality 320k --embed-thumbnail --add-metadata --postprocessor-args \"-id3v2_version 3\" \"%s\"", url);

    //make sure it's soundcloud link
    char *soundcloud = strstr(url, "soundcloud.com");
    if (soundcloud == NULL) {
        printf("Invalid URL: Please enter a SoundCloud URL.\n");
        return;
    }

    system(command);
    printf("\nDownload complete!\n");
    getchar(); // eater
}

int main() {
    title();
    while (1 < 2){
        printf("OPTIONS:\n");
        printf("   1. Download music\n");
        printf("   2. Edit Metadata\n");
        printf("   3. Exit\n");

        printf("Enter your choice (1-3): ");
        switch (getchar()) {
            case '1':
                printf("\n");
                download();
                break;
            case '2':
                printf("\n");
                metadata();
                break;
            case '3':
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}