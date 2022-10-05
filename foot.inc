</div> <!-- content -->

		<div id="right">
			<div id="boxx1">
				<div id="box1">
					<?php
						$content = $pages->get('/settings/right/box1/');
						echo '<img src="';
						echo $content->right_box_titleimg->url;
						echo '" width="160" height="35" border="0" alt="';
						$content->right_box_titleimg->description;
						echo '" /><br />';
						echo $content->body;
					?>
				</div>
			</div>
			<div id="boxx2">
				<div id="box2">
					<?php
						$content = $pages->get('/settings/right/box2/');
						echo '<img src="';
						echo $content->right_box_titleimg->url;
						echo '" width="160" height="35" border="0" alt="';
						$content->right_box_titleimg->description;
						echo '" /><br />';
						echo $content->body;
					?>
				</div>
			</div>
			<div id="boxx3"> 
				<div id="box3">
					<?php
						$content = $pages->get('/settings/right/box3/');
						echo '<img src="';
						echo $content->right_box_titleimg->url;
						echo '" width="160" height="35" border="0" alt="';
						$content->right_box_titleimg->description;
						echo '" /><br />';
						echo $content->body;
					?>
				</div>
			</div>
			<div id="boxx4">
				<div id="box4">
					<?php include('right_sponsor.inc'); ?>
				</div>
			</div>
			<div id="boxx_spacer">
			</div>
		</div>
	
	</div>

	
	<div id="bottom">
		<div id="fuss">
			<?php
				echo strftime("%A, %d.%m.%Y %H:%M", time());
			?>
		</div>
		<div id="fuss2">
			<div id="boxx5">
			<!-- -->
			</div>
		</div>
		<div id="right4">
		<!-- -->
		</div>
	</div>
</div>

</body>
</html>
