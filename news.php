<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

include("./head.inc"); 

$dateLimit = $pages->get("/news/")->news_archiv_limit;
$dateInSec = $dateLimit*24*3600;
$limit = time() - $dateInSec;

$min = $pages->get("/news/")->news_minimum_count;

/* WERBEBILD FRONTPAGE */
if($pages->get("/news/")->image && ($pages->get("/news/")->date > time())) {
	$img_frnt = $pages->get("/news/")->image;
	echo "<div class='news-frontpage-img'>";
	echo "<a href='{$pages->get("/news/")->image->description}'>";
	echo "<img src='{$img_frnt->url}' alt='{$img_frnt->description}' /></a>";
	echo "</div>";
}
/* ENDE WERBEBILD */

echo "<h2>Aktuelles:</h2>";

$news = $pages->find("template=news_detail, sort=-created, created>{$limit}");

if($news->getTotal()<$min) {
  $news = $pages->find("template=news_detail, sort=-created, limit={$min}");
}


foreach($news as $child) {
    $out = "";
    if(count($child->news_image)) {
       $image = $child->news_image;
       $imageurl = $image->url;
       $thumburl = $image->getCrop('thumbnail')->url;
   } else {
       $imageurl = $thumburl = $config->urls->templates."styles/images/news_placeholder.gif";
       $image = new Page();
   }
    
    $out .= "<div class='news-latest-item'>"; 
    if($child->date) {
      $out .= "<span class='news-latest-date'>".strftime("%d.%m.%y %H:%M", $child->date)."</a></span>";
    } else {
      $out .= "<span class='news-latest-date'>".strftime("%d.%m.%y %H:%M", $child->created)."</a></span>";
    }
    $out .= "<h3><a href='{$child->url}'>{$child->news_title}</a></h3>";   
    $out .= "<a href='{$child->url}'><img src='{$thumburl}' width='160' height='107' alt='{$image->description}' /></a>";
    $out .= $child->news_intro."";
    $out .= "<div class='news-latest-morelink'><a href='{$child->url}'>[mehr]</a></div>";
    $out .= "</div>";
    
    echo $out;
}

include("./foot.inc"); 
