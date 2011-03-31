<?php
// $Id: views-view-table.tpl.php,v 1.8 2009/01/28 00:43:43 merlinofchaos Exp $
/**
 * @file views-view-table.tpl.php
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $class: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * @ingroup views_templates
 */
?>

<?php
  $highlight = '';
	//Find the index value of area to highligh
  $topvalue = 0;
	foreach ($rows as $key => $row){
    if ($row['areacode'] == check_plain($_GET['highlight'])){
      $highlight = $key;
    }
		if($row['value'] > $topvalue){
			$topvalue = $row['value'];
		}
  }
	
?>
<script type="text/javascript">
			// <![CDATA[
    var data = [
			<?php foreach ($rows as $row) { ?>
      	{ value: <?php print $row['value']?> , label: "<?php print $row['areacode']?>" },
			<?php } ?> 
			];
		var topvalue = <?php print $topvalue; ?>;
			$(document).ready(function() {
				try {
					barchart.setOptions({
						defaultColour: 'rgb(158, 215, 255)',
						defaultHighlightColour: 'rgb(167, 6, 32)',
						name: '<?php print $title ?>'
					});
					barchart.load(data);
					barchart.highlightItem(<?php print $highlight ?>);
					barchart.draw($('#chart'), $('#overview'), $('#detail'), topvalue);
				} catch(e) {
					alert('Exception: ' + e.message);
				}
				//$('table.views-table').hide();
			});
			// ]]>
</script>

<div id="flot-chart" style="height:325px">
			<div id="chart" class="view" style="float:left;width:650px;height:300px;"></div>
			<div style="clear:both"></div>
			<div class="overview-container" style="margin-top: 25px;float:right;margin-right:30px;">
			  <span>Overview</span>
			  <div id="overview" class="view" style="width: 200px; height: 60px;"></div>
			  <div id="detail" class="view" style="width:200px;margin-top:10px;"></div>
			</div>
</div>
<div style="clear:both"></div>


<?php
//$data = array(array(1, 'What'), array(2, 'What1'), array(8, 'Hey'));
//$d1 = new flotData($data);
//$bars = new flotStyleBar();
//$d1->bars = $bars->bars;
//print theme('flot_graph', array(), array($d1), array($bars));
?>



