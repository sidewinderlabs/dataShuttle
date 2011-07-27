<?php
// $Id: web_widgets_iframe.tpl.php,v 1.1 2009/06/24 07:38:58 aronnovak Exp $
/**
 * @file
 * Template for the code what to embed in external sites
 */
?>
<div style="width:600px; font-family:'Helvetica Neue', Helvetica, Arial, sans-serif; line-height:20px">
<div style="background-color:#000; padding:0px 5px; font-weight:bold">
<div style="color:#fff; font-size:14px; line-height:25px;"><?php print $title ?></div>
<div style="font-size:11px; color:#ccc"><?php print $site_name ?></div>
<div class="display-tabs" style="font-size:11px; color:#fff"><p>Display: <?php print $tabs ?></p></div>
</div>
<script type="text/javascript">
widgetContext = <?php print $js_variables ?>;
</script>
<div id="<?php print $wid ?>"></div>
<script src="<?php print $script_url ?>"></script>
<script src="<?php print $tabs_script_url ?>"></script>
</div>