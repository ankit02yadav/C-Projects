#include <stdio.h>

#include "bakery/bms.c"
#include "games/games.c"
#include "day date/day_tm.c"
#include "to do list/tdlist.c"
#include "students record/students.c"
#include "movie recommand/movie.c"

int choice;

int bakery()
{
    printf("\033[0;34m"); // blue
    printf("#################################################################\n");
    printf("##                                                             ##\n");
    printf("##      #$^$#$8@        @#^$#    &{$!@       $@@#^$8@          ##\n");
    printf("##      @#     $@@      $#  8@  $!  $@       @#    #$          ##\n");
    printf("##      8?      $#      @#   $#$@   @#       #@    &*          ##\n");
    printf("##      #@     $#       8&    $#    &{       $#                ##\n");
    printf("##      $#^$#@#$        @#          <?         @#!@            ##\n");
    printf("##      &^     $@@      &^          #@             8(          ##\n");
    printf("##      @!      $#      #$          @#       @#    ^&          ##\n");
    printf("##      $@$#$8@$#       $@          $@       !@#$!@#$          ##\n");
    printf("##                                                             ##\n");
    printf("#################################################################\n");
    printf("\033[0;34m"); // default
    printf("\033[0;37m"); // default //WHITE
    main_bakery();
}
int game()
{
    printf("\033[0;32m"); // green
    printf("#################################################################\n");
    printf("##                                                             ##\n");
    printf("##  8#$^$#$8@   #$^$#$8@  @#^$#    &{$!@  #$^$#$8@  !@@#^$8@   ##\n");
    printf("##  $^          @#    $@  $#  8@  $!  $@  @#        @#    #$   ##\n");
    printf("##  #@          8?    $#  @#   $#$@   @#  8?        #@    &*   ##\n");
    printf("##  &$          #@    $#  8&    $#    &{  #@        $#         ##\n");
    printf("##  @!  ^$#@?   $#^$#@#$  @#          <?  $#^$#@#$    @#!@     ##\n");
    printf("##  ?>     <~   &^    $@  &^          #@  &^              8(   ##\n");
    printf("##  :{     +|   @!    $#  #$          @$  @!        @#    ^&   ##\n");
    printf("##  ?}#@$&^$#   $@    @#  $@          $!  #@$^&*!}  !@#$!@#$   ##\n");
    printf("##                                                             ##\n");
    printf("#################################################################\n");
    printf("\033[0;37m"); // default //WHITE
    main_game();
}
int day_date()
{
    printf("\033[0;32m"); // green
    printf("#################################################################\n");
    printf("##                                                             ##\n");
    printf("##      8#$^$@!#$8       #$^$#$?>8@     #$#     &{$            ##\n");
    printf("##      $^       #$      @#      $@      8@     $!             ##\n");
    printf("##      #@       ?$      8?      $#       $#   $@              ##\n");
    printf("##      &$       8&      #@      $#         $##                ##\n");
    printf("##      @!       @?      $#^$$@#@#$          @!                ##\n");
    printf("##      ?>       <~      &^      $@          !~                ##\n");
    printf("##      :{       +|      @!      $#          ?<                ##\n");
    printf("##      ?}#@@!$&^$       $@      @#          #$                ##\n");
    printf("##                                                             ##\n");
    printf("#################################################################\n");
    printf("\033[0;37m"); // default //WHITE
    main_day_date();
}
int to_do_list()
{
    printf("\033[0;31m"); // red
    printf("######################################################################\n");
    printf("##                                                                  ##\n");
    printf("##   <}&#$&#@!>    *#$^$#$8@       @#^$#$8@       @#     $#@        ##\n");
    printf("##       $&        @#     $@      $#     @@       @#   &$!          ##\n");
    printf("##       #$        8?     $#     @#      $#       @# >?!            ##\n");
    printf("##       #@        #@     $#      8&              &{#>              ##\n");
    printf("##       #$        $#^$#@#$(       @#^$#@#$       #? >?!            ##\n");
    printf("##       {]        &^     @#             $#       #@   &$!          ##\n");
    printf("##       #$        @!     &^      @^     $@       @#     $#@        ##\n");
    printf("##       @#        $@     #$      $@@^$#$8        $!       !#       ##\n");
    printf("##                                                                  ##\n");
    printf("######################################################################\n");
    printf("\033[0;37m"); // default //WHITE
    main_tdlist();
}

int srs(){
    printf("\033[0;32m"); // green
    printf("PENDING ...\n");
    printf("##########################################################################\n");
    printf("##                                                                      ##\n");
    printf("##  &}&#$&#@   *#$^$#$8@   @#^$#$8@    @#$#@     &}&#$&#@    $#^$#$8@   ##\n");
    printf("##  $&     @#  $@         @@         @#     &$   $&     @#   @#     $#  ##\n");
    printf("##  #$      8? $#         $#         @#     $!   #$      8?  ?&     @!  ##\n");
    printf("##  #@     #@  $#         &{         &$     #@   #@     #@   >#     ?#  ##\n");
    printf("##  #$$#^$#@   @#^$#@#$#  ?!         @?     $#   #$$#^$#@    $!     !~  ##\n");
    printf("##  {]&^       @#         $#         #@     &$   {]&^        @#     *^  ##\n");
    printf("##  #$ @!      &^         $@         @#     $#   #$  @!      <@     #@  ##\n");
    printf("##  @#   $@    #$$@@^$#$8  $#^$#$8@    $#@!#     @#   $@     $#^$#$8@   ##\n");
    printf("##                                                                      ##\n");
    printf("##########################################################################\n");
    printf("\033[0;37m"); // default //WHITE
    main_students();
}

int movie_recommand(){
    printf("\033[0;34m"); // blue
    printf("######################################################################\n");
    printf("##                                                                  ##\n");
    printf("##                                                                  ##\n");
    printf("##                                                                  ##\n");
    printf("##                                                                  ##\n");
    printf("##                                                                  ##\n");
    printf("##                                                                  ##\n");
    printf("##                                                                  ##\n");
    printf("##                                                                  ##\n");
    printf("##                                                                  ##\n");
    printf("##                                                                  ##\n");
    printf("######################################################################\n");
    printf("\033[0;37m"); // default //WHITE
    main_movies();
}

int main()
{
    while (1)
    {
        printf("\033[0;31m"); // red
        printf("######################################################################\n");
        printf("##                                                                  ##\n");
        printf("##      #$&#@   #$^$#$8@     @#^$#$8@        $!@#$        @#^$#$8@  ##\n");
        printf("##    $&@#      @#     $@@   $#     $@@     @#   #@          #@     ##\n");
        printf("##   @#$        8?      $#   @#      $#    @#     #@         &*     ##\n");
        printf("##   8#@        #@     $#    8&     $#     &{     $#         8(     ##\n");
        printf("##   @#$        $#^$#@#$     @#^$#@#$      #?     ?>         ?|     ##\n");
        printf("##   {?]        &^           &^ $#         #@     <?    @#   !@     ##\n");
        printf("##    @#$!      @!           #$  $@&        @#    @#    ^&   #$     ##\n");
        printf("##      #$@&(   $@           $@    !@#       $!@#$      !@#$!@   *  ##\n");
        printf("##                                                                  ##\n");
        printf("######################################################################\n");
        printf("1. Bakery Management Systwm\n");
        printf("2. Game Menu \n");
        printf("3. Day Finder \n");
        printf("4. To Do List \n");
        printf("5. Student Record System \n");
        printf("6. Movies Recommandation \n");
        printf("7. Exit \n");
        printf("######################################################################\n");
        printf("Enter your choice: ");
        printf("\033[0;37m"); // default //WHITE
        scanf("%d", &choice);
        if (choice == 1)
        {
            bakery();
        }
        else if (choice == 2)
        {
            game();
        }
        else if (choice == 3)
        {
            day_date();
        }
        else if (choice == 4)
        {
            to_do_list();
        }
        else if (choice == 5)
        {
            srs();
        }
        else if (choice == 6)
        {
            movie_recommand();
        }
        else
        {
            break;
        }
    }
}