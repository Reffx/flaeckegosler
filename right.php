<div id="right">
			<div id="boxx1">
				<div id="box1">
					<!--<jdoc:include type="modules" name="box1" />-->
				</div>
			</div>
			<div id="boxx2">
				<div id="box2">
					<!--<jdoc:include type="modules" name="box2" />-->
				</div>
			</div>
			<div id="boxx3"> 
				<div id="box3">
					<!--<jdoc:include type="modules" name="box3" />-->
				</div>
			</div>
			<div id="boxx4">
				<div id="box4">
					<div id="sponsor1">
						<a href="<?php echo ($pages->get('/')->settings_sponsor1_url == NULL) ? '#':$pages->get('/')->settings_sponsor1_url.'" target="_blank"' ?>" >
							<img src="<?php echo $pages->get('/')->settings_sponsor1_img->url ?>" width="160" height="66" border="0" alt="<?php echo $pages->get('/')->settings_sponsor1_img->description ?>" />
						</a>
					</div>
					<div id="sponsor2">
						<a href="<?php echo ($pages->get('/')->settings_sponsor2_url == NULL) ? '#':$pages->get('/')->settings_sponsor2_url.'" target="_blank"' ?>" >
							<img src="<?php echo $pages->get('/')->settings_sponsor2_img->url ?>" width="160" height="66" border="0" alt="<?php echo $pages->get('/')->settings_sponsor2_img->description ?>" />
						</a>
					</div>
					<div id="sponsor3">
						<a href="<?php echo ($pages->get('/')->settings_sponsor3_url == NULL) ? '#':$pages->get('/')->settings_sponsor3_url.'" target="_blank"' ?>" >
							<img src="<?php echo $pages->get('/')->settings_sponsor3_img->url ?>" width="160" height="66" border="0" alt="<?php echo $pages->get('/')->settings_sponsor3_img->description ?>" />
						</a>
					</div>  
					<div id="sponsor4">
					<!-- Sponsor 4 -->
					</div>
				</div>
			</div>
		</div>