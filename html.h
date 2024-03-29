/*
 * file: html.h
 */

#pragma once

#include <stdio.h>
#include "md.h"

/*
 * @HTMLFile
 */
typedef FILE HTMLFile;

typedef enum {
  HTML_TAG_H1,
  HTML_TAG_H2,
  HTML_TAG_H3,
  HTML_TAG_LI,
  HTML_TAG_IMG,
  HTML_TAG_NONE,
} HTMLTag;

typedef struct HTMLUnit {
  HTMLTag tag;
  char *content;
  char *uri;
} HTMLUnit;

typedef struct HTML {
  char *file_name;
  char *title;

  /* content */
  uint n_lines;
  HTMLUnit **html;
} HTML;


HTML *html_from_md (MD   *md);
void  html_free    (HTML *html);
void  flush_html   (HTML *html);
