<?php

include("./head.inc"); 

$ColumnNumber = 4; // Anzahl Spalten
$i = 1; // Wird benutzt um die Spaltenanzahl zu erkennen
$thumbWidth = 140;
$zoomHeight = 600;

$mitglieder = $page->mitglieder->sort('body');

$out = "";

$out .= "<h1>".$page->artikel_titel."</h1>";
$out .= "<br />";
 
$out .= '<table id="mitglieder"><tr>';
foreach($mitglieder as $mitglied) {
	$out .= '<td>';

	if(count($mitglied->mitglieder_image)) {
		$img = $mitglied->mitglieder_image->width($thumbWidth);
		$img2 = $mitglied->mitglieder_image->width(2*$thumbWidth);
		$img3 = $mitglied->mitglieder_image->width(3*$thumbWidth);
		$out .= '<img src ="'.$img->url.'" srcset="'.$img->url.' 1x, '.$img2->url.' 2x, '.$img3->url.' 3x" alt="" align="top" border="0" /><br />';
	} else {
		$out .= '<img src ="'.$config->urls->templates."styles/images/portrait_placeholder_140x210.jpg".'" alt="" align="top" border="0" /><br />';
	}

	$out .= $mitglied->body;
	$out .= '</td>';
	if(($i % $ColumnNumber) == 0) {
		$out .= '</tr><tr>';
	}
	$i++;
}
$out .= '</tr></table>';
echo $out;

include("./foot.inc"); 
