<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">

<head>
<?php print $head ?>
<?php print $styles ?>
<?php print $scripts ?>
<title><?php print $head_title ?></title>
</head>

<body class="maintenance">
<div id="page">

<?php if ($header): ?><div id="header" class='clear-block'><?php print $header; ?></div><?php endif; ?>

<div id='branding' class='clear-block'>

  <?php if ($site_name): ?><h1 class='site-name'><?php print $site_name ?></h1><?php endif; ?>

  <?php if ($site_slogan): ?><div class='site-slogan'><?php print $site_slogan ?></div><?php endif; ?>

  <?php if ($admin_link): ?><div class="admin-link"><?php //print $admin_link; ?></div><?php endif; ?>

  <?php if (isset($primary_links)) : ?>
    <?php //print theme('links', $primary_links, array('class' => 'links primary-links')) ?>
  <?php endif; ?>
</div>

<div id='canvas' class='clear-block'>

  <div id='page-header' class='clear-block'>

  <?php if ($page_title || $title): ?>
    <div id='page-title'>
      <?php if ($page_title) print $page_title ?>
      <?php if ($title && empty($page_title)): ?><h2 class='page-title'><?php print $title ?></h2><?php endif; ?>
    </div>
  <?php endif; ?>

  </div>

  <div id='main'>
    <div id='content' class='page-content clear-block'>
      <div id='content-wrapper'><?php print $content ?></div>
      <div id='content-region-wrapper'><?php print $content_region ?></div>
    </div>
  </div>

</div>

<?php include 'page.footer.inc'; ?>
