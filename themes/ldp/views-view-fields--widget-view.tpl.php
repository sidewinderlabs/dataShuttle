<?php
// $Id: views-view-fields.tpl.php,v 1.6 2008/09/24 22:48:21 merlinofchaos Exp $
/**
 * @file views-view-fields.tpl.php
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->separator: an optional separator that may appear before a field.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php
$packageToMethod = array(
  "columnchart" => "ColumnChart",
  "piechart" => "PieChart"
);
if (arg(0) == 'mrsa-2009' && arg(1)) {
	$args[0] = arg(1);
} else if (arg(0) == 'organisation' && arg(1)) {
	$args[0] = arg(1);
} else {
	$node = menu_get_object();
	$args[0] = $node->field_org_code[0]['value'];
}
$query = $fields['field_query_select_value']->raw . '"' . $args[0] . '"';
/* print $query; */
?>
<script type="text/javascript" src="http://www.google.com/jsapi">/**/</script>
<script type="text/javascript">
      google.load('visualization', '1', {'packages':['<?php print $fields['field_chart_type_value']->raw ?>']});
      // Set a callback to run when the Google Visualization API is loaded.
      google.setOnLoadCallback(drawChart);
      // Callback that creates and populates a data table,
      // instantiates the chart, passes in the data and
      // draws it.
      function drawChart() {
      // Create our data table.
var query = new google.visualization.Query('<?php print $fields['field_chart_query_url']->raw; ?>');
query.setQuery('<?php print $query; ?>');
query.send(
  function(response) {
    if (response.isError()) {
      alert('Error in query: ' + response.getMessage() + ' ' + response.getDetailedMessage());
      return;
    }
    // Instantiate and draw our chart, passing in some options.
    var chart = new google.visualization.<?php print $packageToMethod[$fields['field_chart_type_value']->raw] ?>(document.getElementById('chart_div'));
    chart.draw(response.getDataTable(), {title: '<?php print $packageToMethod[$fields['title']->content] ?>', height: 100, legend: 'none'});
  }
);
}
</script>
<div id="chart_div"></div>
<!--
<?php foreach ($fields as $id => $field): ?>
  <?php if (!empty($field->separator)): ?>
    <?php print $field->separator; ?>
  <?php endif; ?>

  <<?php print $field->inline_html;?> class="views-field-<?php print $field->class; ?>">
    <?php if ($field->label): ?>
      <label class="views-label-<?php print $field->class; ?>">
        <?php print $field->label; ?> (<?php print $id; ?>:)
      </label>
    <?php endif; ?>
      <?php
      // $field->element_type is either SPAN or DIV depending upon whether or not
      // the field is a 'block' element type or 'inline' element type.
      ?>
      <<?php print $field->element_type; ?> class="field-content"><?php print $field->raw; ?></<?php print $field->element_type; ?>>
  </<?php print $field->inline_html;?>>
<?php endforeach; ?>
-->
