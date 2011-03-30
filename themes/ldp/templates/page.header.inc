<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">

<head>
<?php print $head ?>
<?php print $styles ?>

<!--[if lt IE 8]>
<link type="text/css" rel="stylesheet" media="all" href="<?php print base_path() . drupal_get_path('theme', 'ldp'); ?>/css/ie7-fix.css" />
<![endif]-->

<!--[if lt IE 7]>
<link type="text/css" rel="stylesheet" media="all" href="<?php print base_path() . drupal_get_path('theme', 'ldp'); ?>/css/ie6-fix.css" />
<![endif]-->

<?php print $scripts ?>
<!--[if IE]><script language="javascript" type="text/javascript" src="<?php print base_path() ?>sites/all/libraries/flot/excanvas.min.js"></script><![endif]-->
<title><?php print $head_title ?></title>
</head>

<body <?php print drupal_attributes($attr) ?>>
<div id="page">

<?php if (!empty($admin)) print $admin ?>

<?php if ($header): ?><div id="header" class='clear-block'><?php print $header; ?></div><?php endif; ?>

<div id='branding' class='clear-block'>

  <?php if ($site_name): ?><h1 class='site-name'><a href="/" class="logo active">National Innovation Centre</a></h1><?php endif; ?>

  <?php if ($site_slogan): ?><div class='site-slogan'><?php print $site_slogan ?></div><?php endif; ?>

  <?php if ($admin_link): ?><div class="admin-link"><?php //print $admin_link; ?></div><?php endif; ?>

  <?php if (isset($primary_links)) : ?>
    <?php //print theme('links', $primary_links, array('class' => 'links primary-links')) ?>
  <?php endif; ?>
</div>
