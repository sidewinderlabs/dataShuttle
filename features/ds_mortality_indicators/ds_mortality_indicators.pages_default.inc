<?php

/**
 * Implementation of hook_default_page_manager_pages().
 */
function ds_mortality_indicators_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'indicators';
  $page->task = 'page';
  $page->admin_title = 'Indicators';
  $page->admin_description = '';
  $page->path = 'indicator/%icd10range/%subject/%geographicalunit/year/%year';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'icd10range' => array(
      'id' => 1,
      'identifier' => 'ICD10Range',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'subject' => array(
      'id' => 3,
      'identifier' => 'Subject',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'geographicalunit' => array(
      'id' => 4,
      'identifier' => 'GeographicalUnit',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'year' => array(
      'id' => 2,
      'identifier' => 'Year',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_indicators_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'indicators';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
          1 => 2,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '76.90885191783502',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'viewsresults',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      2 => array(
        'type' => 'column',
        'width' => '23.09114808216498',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 3,
        ),
        'class' => '',
      ),
      'viewsresults' => array(
        'type' => 'region',
        'title' => 'ViewsResults',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar',
        ),
        'parent' => '2',
        'class' => '',
      ),
      'sidebar' => array(
        'type' => 'region',
        'title' => 'Sidebar',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'center' => NULL,
      'sidebar' => NULL,
      'viewsresults' => array(
        'title' => '',
        'filling_tabs' => 'disabled',
      ),
    ),
    'viewsresults' => array(
      'style' => 'tabs',
    ),
  );
  $display->cache = array();
  $display->title = '%year:html_safe Results';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'indicator_details-indicator_body_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'indicator_years-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-2'] = $pane;
    $display->panels['sidebar'][0] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'indicator_details-indicator_source';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-3'] = $pane;
    $display->panels['sidebar'][1] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'indicator_details-indicator_quality';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-4'] = $pane;
    $display->panels['sidebar'][2] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'viewsresults';
    $pane->type = 'views_panes';
    $pane->subtype = 'indicator_results-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-5'] = $pane;
    $display->panels['viewsresults'][0] = 'new-5';
    $pane = new stdClass;
    $pane->pid = 'new-6';
    $pane->panel = 'viewsresults';
    $pane->type = 'views_panes';
    $pane->subtype = 'indicator_results-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-6'] = $pane;
    $display->panels['viewsresults'][1] = 'new-6';
    $pane = new stdClass;
    $pane->pid = 'new-7';
    $pane->panel = 'viewsresults';
    $pane->type = 'views_panes';
    $pane->subtype = 'indicator_results-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-7'] = $pane;
    $display->panels['viewsresults'][2] = 'new-7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['indicators'] = $page;

 return $pages;

}
