<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xml:lang="de" lang="de" xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta name="msvalidate.01" content="EA3DF131009E710522C6C26D48B89996" />
<title>Fläckegosler Roteborg</title>

<link rel="stylesheet" type="text/css" href="<?php echo $config->urls->templates?>styles/layoutscreen.css" media="all"/>
<link rel="stylesheet" type="text/css" href="<?php echo $config->urls->templates?>styles/stylesheet.css" />
<link rel="stylesheet" type="text/css" href="<?php echo $config->urls->templates?>styles/lightbox.css" />

<script src="<?php echo $config->urls->templates?>scripts/jquery-1.11.0.min.js"></script>
<script src="<?php echo $config->urls->templates?>scripts/lightbox.min.js"></script>

<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<meta name="description" content="<?php echo $pages->get('/settings/settingshead')->meta_description ?>" />
<meta name="keywords" content="<?php echo $pages->get('/settings/settingshead')->meta_keywords ?>" />
<?php 
	if($page->parents->has('mitglieder')) {
		echo '<meta name="robots" content="nofollow" />';
		echo '<meta name="robots" content="noindex" />';
	}
?>
</head>

<body>

<div id="ausrichtung"> 
	<div id="top">
		<div id="logo"><a href="<?php echo $config->urls->root ?>" ><img src="<?php echo $pages->get('/settings/settingshead')->settings_logo_left->url ?>" width="250" height="200" border="0" alt="Fläckegosler Roteborg" /></a></div>
			<div id="ckopf">
				<div id="kopf">
				</div>
			<div id="icon">
				<a href="<?php echo $config->urls->root ?>">
					<img src="<?php echo $config->urls->templates?>styles/images/icon01.gif" onmouseover="this.src='<?php echo $config->urls->templates?>styles/images/icon012.gif';" onmouseout="this.src='<?php echo $config->urls->templates?>styles/images/icon01.gif'" width="36" height="30" border="0" alt="Home" />
				</a>
				<a href="<?php echo $pages->get("/iconpages/kontakt/")->url ?>">
					<img src="<?php echo $config->urls->templates?>styles/images/icon02.gif" onmouseover="this.src='<?php echo $config->urls->templates?>styles/images/icon022.gif';" onmouseout="this.src='<?php echo $config->urls->templates?>styles/images/icon02.gif'"  width="36" height="30" border="0" alt="Kontakt" />
				</a>
				<a href="<?php echo $pages->get("/boxpages/zu-verkaufen/")->url ?>">
					<img src="<?php echo $config->urls->templates?>styles/images/icon03.gif" onmouseover="this.src='<?php echo $config->urls->templates?>styles/images/icon032.gif';" onmouseout="this.src='<?php echo $config->urls->templates?>styles/images/icon03.gif'"  width="36" height="30" border="0" alt="Shop" />
				</a>
				<a href="<?php echo $pages->get("/iconpages/sitemap/")->url ?>">
					<img src="<?php echo $config->urls->templates?>styles/images/icon04.gif" onmouseover="this.src='<?php echo $config->urls->templates?>styles/images/icon042.gif';" onmouseout="this.src='<?php echo $config->urls->templates?>styles/images/icon04.gif'"  width="36" height="30" border="0" alt="Sitemap" />
				</a>
			</div>
			<div id="right1">
			</div>
			<div id="bild"><img src="<?php echo $pages->get('/settings/settingshead')->settings_headerimg->getRandom()->url ?>" width="655" height="150" border="0" alt="" /></div>
				<div id="expedition">
					<a href="<?php echo $pages->get('/settings/settingshead')->link ?>" target="_blank" >
						<img src="<?php echo $pages->get('/settings/settingshead/')->settings_logo_right->url ?>" width="210" height="150" border="0" alt="" />
					</a>
				</div>
			<div id="right2">
			</div>
		</div>
		<div id="cbn">
			<div id="bn">
				<?php
				/* Breadcrumbs */
                                
                                // Excludes that shouldn't be shown; Titelnamen verwenden nicht linkname!
                                $excludes = array("gosler", "iconpages", "boxpages", "news artikel"); // small letters!!!!!!
								
				foreach($page->parents as $parent) {
                                    if(in_array(strtolower($parent->title), $excludes)) {continue;}
                                    echo "<a href='{$parent->url}'> {$parent->title}</a> &gt; ";
				}
                                echo $page->title;
				?>
			</div>
		</div>
	<!-- Breadcrumbs -->
</div>

    
	<div id="center">
		<div id="hn">
			<?php
			
				// Create the navigation list by listing the children of the homepage. 
				// If the section we are in is the current (identified by $page->rootParent)
				// then note it with <a class='aktiv'> otherwise <a class='normal'> so we can style it differently in our CSS. 
				// In this case we also want the homepage to be part of our top navigation, 
				// so we prepend it to the pages we cycle through:
				
				$homepage = $pages->get("/");
				//$menu = $homepage->children; 
        $menu = $pages->find("parent=/, sort=sort"); // Use this variant to hide the not accessible sites for guest users
				
				$class = ($homepage->id == wire('page')->id) ? " class='aktiv'" : " class='normal'";
                                
				listMenu($menu);
				
				function listMenu($children) {
					echo '<ul>';
					foreach($children as $child) {
						$class = (($child === wire('page')) || ($child === wire('page')->parent) || ($child === wire('page')->rootParent)) ? " class='aktiv'" : " class='normal'";
						echo "<li><a$class href='{$child->url}'>{$child->title}</a>";
                                                if(($child === wire('page')) || ($child === wire('page')->parent) || ($child === wire('page')->rootParent)) {
                                                    listMenu($child->children);
                                                }
						echo '</li>';
					}
					echo '</ul>';
				}
				
				
				/* Menu ausgeben... halt nicht Rekursiv... 
				*  Problem war, dass die oberste Ebene nicht gleich detektiert wird wie
				*  die unteren ebenen welche aktiv sind... 
				*  Unterschied: wire('page')->rootParent->id ... zu ... wire('page')->id
				*/
				/*
				echo '<ul>';
				foreach($menu as $page) {
					$class = ($page->id == wire('page')->rootParent->id) ? " class='aktiv'" : " class='normal'";
					echo "<li><a$class href='{$page->url}'>{$page->title}</a>";
					// zweite Ebene
					if((wire('page')->rootParent->id == $page->id) & (wire('page')->id != 1)) {
						$page1 = $page->children;
						echo '<ul>';
						foreach($page->children as $page1) {
							$class = ($page1->id == wire('page')->id) ? " class='aktiv'" : " class='normal'";
							echo "<li><a$class href='{$page1->url}'>{$page1->title}</a>";
							// dritte Ebene
							if(wire('page')->id == $page1->id) {
								echo '<ul>';
								foreach($page1->children as $page2) {
									$class = ($page2->id == wire('page')->id) ? " class='aktiv'" : " class='normal'";
									echo "<li><a$class href='{$page2->url}'>{$page2->title}</a></li>";
								}
								echo '</ul>';
							}
						}
						echo '</ul></lI>';
					} else {
						echo "</li>";
					}
				}
				echo '</ul>';
				*/
			?>
		</div>

		<div id="content">
                    
